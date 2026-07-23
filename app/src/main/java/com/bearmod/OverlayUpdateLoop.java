package com.bearmod;

import android.graphics.Point;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;
import android.view.View;

import androidx.annotation.NonNull;

import java.lang.ref.WeakReference;

/**
 * Runs overlay frame invalidation and display-size polling on the main looper.
 */
public final class OverlayUpdateLoop {
    private static final long SCREEN_SIZE_POLL_MS = 250L;

    public interface Callback {
        View getCanvasView();

        boolean readScreenSize(Point outSize);

        int getKnownScreenWidth();

        int getKnownScreenHeight();

        int getMaxFps();

        void onScreenSizeChanged();
    }

    private final Handler handler = new Handler(Looper.getMainLooper());
    private final WeakReference<Callback> callbackRef;
    private boolean running;

    private final Runnable canvasRunnable = new Runnable() {
        @Override
        public void run() {
            if (!running) {
                return;
            }
            long startedAt = SystemClock.uptimeMillis();
            Callback callback = callbackRef.get();
            if (callback == null) {
                stop();
                return;
            }
            View canvas = callback.getCanvasView();
            if (canvas != null) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
                    canvas.postInvalidateOnAnimation();
                } else {
                    canvas.postInvalidate();
                }
            }
            long elapsed = SystemClock.uptimeMillis() - startedAt;
            long interval = 1000L / Math.max(1, callback.getMaxFps());
            schedule(this, interval - elapsed);
        }
    };

    private final Runnable displayRunnable = new Runnable() {
        private final Point displaySize = new Point();

        @Override
        public void run() {
            if (!running) {
                return;
            }
            long startedAt = SystemClock.uptimeMillis();
            Callback callback = callbackRef.get();
            if (callback == null) {
                stop();
                return;
            }
            if (callback.readScreenSize(displaySize)
                    && (callback.getKnownScreenWidth() != displaySize.x
                    || callback.getKnownScreenHeight() != displaySize.y)) {
                callback.onScreenSizeChanged();
            }
            long elapsed = SystemClock.uptimeMillis() - startedAt;
            schedule(this, SCREEN_SIZE_POLL_MS - elapsed);
        }
    };

    public OverlayUpdateLoop(@NonNull Callback callback) {
        callbackRef = new WeakReference<>(callback);
    }

    public void start() {
        if (running) {
            return;
        }
        running = true;
        handler.post(displayRunnable);
        handler.post(canvasRunnable);
    }

    public void stop() {
        if (!running) {
            return;
        }
        running = false;
        handler.removeCallbacks(displayRunnable);
        handler.removeCallbacks(canvasRunnable);
    }

    private void schedule(Runnable runnable, long delayMillis) {
        if (running) {
            handler.postDelayed(runnable, Math.max(0L, delayMillis));
        }
    }
}
