package com.bearmod;

import android.content.Context;
import android.content.SharedPreferences;
import androidx.annotation.NonNull;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
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
    private final Object flushLock = new Object();

    private ConfigManager() {
        // private
    }

    public static ConfigManager getInstance() {
        return INSTANCE;
    }

    public void initialize(@NonNull SharedPreferences prefs) {
        this.prefs = prefs;
        if (ioExecutor == null) ioExecutor = Executors.newSingleThreadExecutor();
        if (scheduler == null) scheduler = Executors.newSingleThreadScheduledExecutor();
        loadFromPrefs();
    }

    private void loadFromPrefs() {
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
        if (value == null) {
            map.remove(key);
        } else {
            map.put(key, value);
        }
        scheduleFlush();
    }

    private void scheduleFlush() {
        synchronized (flushLock) {
            if (scheduledFlush != null) scheduledFlush.cancel(false);
            scheduledFlush = scheduler.schedule(this::flushToPrefs, 500, TimeUnit.MILLISECONDS);
        }
    }

    private void flushToPrefs() {
        if (prefs == null) return;
        final Map<String, String> snapshot = new ConcurrentHashMap<>(map);
        ioExecutor.execute(() -> {
            SharedPreferences.Editor e = prefs.edit();
            for (Map.Entry<String, String> ent : snapshot.entrySet()) {
                e.putString(ent.getKey(), ent.getValue());
            }
            e.apply();
        });
    }

    public Map<String, String> getMap() {
        return map;
    }

    public void shutdown() {
        synchronized (flushLock) {
            if (scheduledFlush != null) {
                scheduledFlush.cancel(false);
                scheduledFlush = null;
            }
        }
        if (prefs != null) {
            Map<String, String> snapshot = new ConcurrentHashMap<>(map);
            SharedPreferences.Editor e = prefs.edit();
            for (Map.Entry<String, String> ent : snapshot.entrySet()) {
                e.putString(ent.getKey(), ent.getValue());
            }
            e.apply();
        }
        if (ioExecutor != null) {
            ioExecutor.shutdownNow();
            ioExecutor = null;
        }
        if (scheduler != null) {
            scheduler.shutdownNow();
            scheduler = null;
        }
        prefs = null;
    }
}
