package com.bearmod;

import android.view.View;
import android.view.WindowManager;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.List;

/**
 * Owns every WindowManager mutation made by the floating overlay service.
 *
 * <p>The registry keeps teardown idempotent and prevents one overlay root from
 * being removed twice when service shutdown overlaps with feature cleanup.</p>
 */
public final class OverlayWindowRegistry {
    private final WindowManager windowManager;
    private final List<View> attachedViews = new ArrayList<>();
    private boolean closed;

    public OverlayWindowRegistry(@NonNull WindowManager windowManager) {
        this.windowManager = windowManager;
    }

    public synchronized boolean add(
            @Nullable View view,
            @Nullable WindowManager.LayoutParams layoutParams
    ) {
        if (closed || view == null || layoutParams == null) {
            return false;
        }
        if (attachedViews.contains(view) || view.getParent() != null) {
            track(view);
            return true;
        }
        try {
            windowManager.addView(view, layoutParams);
            track(view);
            return true;
        } catch (RuntimeException ignored) {
            return false;
        }
    }

    public synchronized boolean update(
            @Nullable View view,
            @Nullable WindowManager.LayoutParams layoutParams
    ) {
        if (closed || view == null || layoutParams == null || view.getParent() == null) {
            return false;
        }
        try {
            windowManager.updateViewLayout(view, layoutParams);
            track(view);
            return true;
        } catch (RuntimeException ignored) {
            return false;
        }
    }

    public synchronized boolean remove(@Nullable View view) {
        return removeInternal(view, false);
    }

    public synchronized boolean removeImmediate(@Nullable View view) {
        return removeInternal(view, true);
    }

    private boolean removeInternal(@Nullable View view, boolean immediate) {
        if (view == null) {
            return false;
        }
        if (view.getParent() == null) {
            attachedViews.remove(view);
            return true;
        }
        try {
            if (immediate) {
                windowManager.removeViewImmediate(view);
            } else {
                windowManager.removeView(view);
            }
            attachedViews.remove(view);
            return true;
        } catch (RuntimeException ignored) {
            return false;
        }
    }

    private void track(View view) {
        if (!attachedViews.contains(view)) {
            attachedViews.add(view);
        }
    }

    /**
     * Removes all registered overlay roots in reverse registration order.
     * Calling this method more than once is safe.
     */
    public synchronized void shutdown() {
        if (closed) {
            return;
        }
        closed = true;
        List<View> views = new ArrayList<>(attachedViews);
        for (int i = views.size() - 1; i >= 0; i--) {
            View view = views.get(i);
            if (view == null || view.getParent() == null) {
                continue;
            }
            try {
                windowManager.removeViewImmediate(view);
            } catch (RuntimeException ignored) {
            }
        }
        attachedViews.clear();
    }
}
