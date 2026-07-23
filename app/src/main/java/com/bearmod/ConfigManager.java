package com.bearmod;

import android.content.SharedPreferences;
import androidx.annotation.NonNull;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;

/**
 * Thread-safe configuration manager that persists to SharedPreferences off the UI thread.
 */
public class ConfigManager {
    private static final ConfigManager INSTANCE = new ConfigManager();

    private final Map<String, String> map = new ConcurrentHashMap<>();
    private SharedPreferences prefs;
    private ExecutorService ioExecutor;
    private ScheduledExecutorService scheduler;
    private ScheduledFuture<?> scheduledFlush;
    private long flushGeneration;
    private final Object lifecycleLock = new Object();

    private ConfigManager() {
        // private
    }

    public static ConfigManager getInstance() {
        return INSTANCE;
    }

    public void initialize(@NonNull SharedPreferences prefs) {
        synchronized (lifecycleLock) {
            this.prefs = prefs;
            if (ioExecutor == null || ioExecutor.isShutdown()) {
                ioExecutor = Executors.newSingleThreadExecutor();
            }
            if (scheduler == null || scheduler.isShutdown()) {
                scheduler = Executors.newSingleThreadScheduledExecutor();
            }
            loadFromPrefsLocked();
        }
    }

    private void loadFromPrefsLocked() {
        if (prefs == null) return;
        map.clear();
        Map<String, ?> all = prefs.getAll();
        for (Map.Entry<String, ?> e : all.entrySet()) {
            Object v = e.getValue();
            map.put(e.getKey(), v != null ? v.toString() : null);
        }
    }

    public String getString(String key, String def) {
        String v = map.get(key);
        return v != null ? v : def;
    }

    public int getInt(String key, int def) {
        String v = map.get(key);
        try {
            return v != null ? Integer.parseInt(v) : def;
        } catch (NumberFormatException e) {
            return def;
        }
    }

    public boolean getBoolean(String key, boolean def) {
        String v = map.get(key);
        if (v == null) return def;
        return "1".equals(v) || Boolean.parseBoolean(v);
    }

    public void put(final String key, final String value) {
        if (key == null) return;
        synchronized (lifecycleLock) {
            if (value == null) {
                map.remove(key);
            } else {
                map.put(key, value);
            }
            scheduleFlush();
        }
    }

    private void scheduleFlush() {
        synchronized (lifecycleLock) {
            if (prefs == null || scheduler == null || scheduler.isShutdown()) {
                return;
            }
            if (scheduledFlush != null) {
                scheduledFlush.cancel(false);
            }
            try {
                final long generation = ++flushGeneration;
                scheduledFlush = scheduler.schedule(
                        () -> flushToPrefs(generation),
                        500,
                        TimeUnit.MILLISECONDS
                );
            } catch (RejectedExecutionException ignored) {
                scheduledFlush = null;
            }
        }
    }

    private void flushToPrefs(long generation) {
        final SharedPreferences targetPrefs;
        final ExecutorService targetExecutor;
        final Map<String, String> snapshot;
        synchronized (lifecycleLock) {
            if (generation != flushGeneration) {
                return;
            }
            scheduledFlush = null;
            if (prefs == null || ioExecutor == null || ioExecutor.isShutdown()) {
                return;
            }
            targetPrefs = prefs;
            targetExecutor = ioExecutor;
            snapshot = new HashMap<>(map);
        }
        try {
            targetExecutor.execute(() -> persist(targetPrefs, snapshot, false));
        } catch (RejectedExecutionException ignored) {
        }
    }

    public Map<String, String> getMap() {
        return map;
    }

    public void shutdown() {
        final SharedPreferences targetPrefs;
        final Map<String, String> snapshot;
        final ExecutorService targetExecutor;
        final ScheduledExecutorService targetScheduler;
        synchronized (lifecycleLock) {
            if (scheduledFlush != null) {
                scheduledFlush.cancel(false);
                scheduledFlush = null;
            }
            flushGeneration++;
            targetPrefs = prefs;
            snapshot = new HashMap<>(map);
            targetExecutor = ioExecutor;
            targetScheduler = scheduler;
            prefs = null;
            ioExecutor = null;
            scheduler = null;
        }

        if (targetScheduler != null) {
            targetScheduler.shutdownNow();
        }
        if (targetExecutor != null) {
            targetExecutor.shutdown();
            try {
                if (!targetExecutor.awaitTermination(1, TimeUnit.SECONDS)) {
                    targetExecutor.shutdownNow();
                }
            } catch (InterruptedException interrupted) {
                targetExecutor.shutdownNow();
                Thread.currentThread().interrupt();
            }
        }
        if (targetPrefs != null) {
            persist(targetPrefs, snapshot, true);
        }
    }

    private static void persist(
            SharedPreferences targetPrefs,
            Map<String, String> snapshot,
            boolean synchronous
    ) {
        SharedPreferences.Editor editor = targetPrefs.edit();
        for (Map.Entry<String, String> entry : snapshot.entrySet()) {
            editor.putString(entry.getKey(), entry.getValue());
        }
        if (synchronous) {
            editor.commit();
        } else {
            editor.apply();
        }
    }
}
