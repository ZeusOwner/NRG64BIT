package com.bearmod;

import android.content.Context;
import android.util.DisplayMetrics;

final class UIDimensions {
    static final int SMALL_PHONE = 0;
    static final int NORMAL_PHONE = 1;
    static final int LARGE_PHONE = 2;
    static final int TABLET = 3;

    final float density;
    final int screenWidthPx;
    final int screenHeightPx;
    final float screenWidthDp;
    final float screenHeightDp;
    final int category;

    final int menuWidthPx;
    final int menuHeightPx;
    final int overlayMarginPx;

    final int panelRadiusPx;
    final int panelStrokePx;
    final int headerHeightPx;

    final int sidebarWidthPx;
    final int sidebarButtonHeightPx;
    final int sidebarButtonSpacingPx;
    final int sidebarGapPx;
    final int sidebarPaddingPx;
    final int sidebarIndicatorWidthPx;
    final int sidebarIndicatorHeightPx;

    final int contentPaddingHorizontalPx;
    final int contentPaddingBottomPx;

    final int toggleRowHeightPx;
    final int seekRowHeightPx;
    final int segmentedRowHeightPx;
    final int rowVerticalPaddingPx;
    final int dividerMarginTopPx;
    final int dividerMarginBottomPx;

    final int switchWidthPx;
    final int switchHeightPx;
    final int switchThumbPx;
    final int seekThumbPx;
    final int segmentedHeightPx;
    final int segmentedInnerPaddingPx;
    final int segmentedOptionPaddingPx;
    final int seekLabelWidthPx;
    final int segmentedLabelWidthPx;
    final int valueWidthPx;
    final int iconSizePx;

    final float titleSp;
    final float sidebarSp;
    final float labelSp;
    final float sectionSp;
    final float valueSp;
    final float segmentedSp;

    UIDimensions(Context context, int screenWidthPx, int screenHeightPx) {
        DisplayMetrics metrics = context.getResources().getDisplayMetrics();
        density = metrics.density > 0 ? metrics.density : 1.0f;
        this.screenWidthPx = screenWidthPx;
        this.screenHeightPx = screenHeightPx;
        screenWidthDp = screenWidthPx / density;
        screenHeightDp = screenHeightPx / density;
        float shortestDp = Math.min(screenWidthDp, screenHeightDp);

        if (shortestDp < 360.0f) {
            category = SMALL_PHONE;
        } else if (shortestDp <= 411.0f) {
            category = NORMAL_PHONE;
        } else if (shortestDp < 600.0f) {
            category = LARGE_PHONE;
        } else {
            category = TABLET;
        }

        overlayMarginPx = dp(12.0f);
        panelRadiusPx = dp(8.0f);
        panelStrokePx = Math.max(1, dp(1.0f));

        float widthDp;
        float heightDp;
        if (category == SMALL_PHONE) {
            widthDp = Math.min(screenWidthDp * 0.94f, 560.0f);
            heightDp = Math.min(screenHeightDp * 0.68f, 300.0f);
            widthDp = clamp(widthDp, 300.0f, Math.max(300.0f, screenWidthDp - 24.0f));
            heightDp = clamp(heightDp, 240.0f, Math.max(240.0f, screenHeightDp - 24.0f));
        } else if (category == NORMAL_PHONE) {
            widthDp = Math.min(screenWidthDp * 0.88f, 600.0f);
            heightDp = Math.min(screenHeightDp * 0.58f, 316.0f);
            widthDp = clamp(widthDp, 520.0f, Math.max(520.0f, screenWidthDp - 24.0f));
            heightDp = clamp(heightDp, 280.0f, Math.max(280.0f, screenHeightDp - 24.0f));
        } else if (category == LARGE_PHONE) {
            widthDp = Math.min(screenWidthDp * 0.84f, 640.0f);
            heightDp = Math.min(screenHeightDp * 0.56f, 330.0f);
            widthDp = clamp(widthDp, 560.0f, Math.max(560.0f, screenWidthDp - 24.0f));
            heightDp = clamp(heightDp, 292.0f, Math.max(292.0f, screenHeightDp - 24.0f));
        } else {
            widthDp = clamp(screenWidthDp * 0.58f, 620.0f, 720.0f);
            heightDp = clamp(screenHeightDp * 0.42f, 330.0f, 420.0f);
        }

        widthDp = Math.min(widthDp, Math.max(300.0f, screenWidthDp - 24.0f));
        heightDp = Math.min(heightDp, Math.max(240.0f, screenHeightDp - 24.0f));
        float aspectRatio = widthDp / Math.max(1.0f, heightDp);
        if (aspectRatio < 1.65f) {
            heightDp = Math.max(240.0f, widthDp / 1.65f);
        } else if (aspectRatio > 2.05f) {
            widthDp = Math.min(widthDp, heightDp * 2.05f);
        }
        menuWidthPx = dp(widthDp);
        menuHeightPx = dp(heightDp);

        float headerHeightDp = category == SMALL_PHONE ? 34.0f : 36.0f;
        headerHeightPx = dp(headerHeightDp);
        sidebarWidthPx = dp(category == SMALL_PHONE ? 108.0f : category == NORMAL_PHONE ? 124.0f : category == LARGE_PHONE ? 132.0f : 140.0f);
        float sidebarButtonSpacingDp = category <= NORMAL_PHONE ? 4.0f : 5.0f;
        sidebarButtonSpacingPx = dp(sidebarButtonSpacingDp);
        sidebarGapPx = dp(category == SMALL_PHONE ? 10.0f : 12.0f);
        float sidebarPaddingDp = 3.0f;
        sidebarPaddingPx = dp(sidebarPaddingDp);
        sidebarIndicatorWidthPx = dp(3.0f);
        sidebarIndicatorHeightPx = dp(16.0f);

        contentPaddingHorizontalPx = dp(category == SMALL_PHONE ? 8.0f : 10.0f);
        float contentPaddingBottomDp = 8.0f;
        contentPaddingBottomPx = dp(contentPaddingBottomDp);
        float preferredSidebarButtonDp = category == SMALL_PHONE ? 34.0f : category == NORMAL_PHONE ? 36.0f : 38.0f;
        float availableSidebarDp = heightDp - headerHeightDp - contentPaddingBottomDp - (sidebarPaddingDp * 2.0f);
        float maxSidebarButtonDp = (availableSidebarDp - (sidebarButtonSpacingDp * 5.0f)) / 6.0f;
        sidebarButtonHeightPx = dp(clamp(Math.min(preferredSidebarButtonDp, maxSidebarButtonDp), 30.0f, preferredSidebarButtonDp));
        toggleRowHeightPx = dp(category == SMALL_PHONE ? 38.0f : 40.0f);
        seekRowHeightPx = dp(category == SMALL_PHONE ? 42.0f : 44.0f);
        segmentedRowHeightPx = seekRowHeightPx;
        rowVerticalPaddingPx = dp(3.0f);
        dividerMarginTopPx = dp(4.0f);
        dividerMarginBottomPx = dp(5.0f);

        switchWidthPx = dp(category == SMALL_PHONE ? 36.0f : category == TABLET ? 40.0f : 38.0f);
        switchHeightPx = dp(category == SMALL_PHONE ? 20.0f : 22.0f);
        switchThumbPx = dp(category == SMALL_PHONE ? 18.0f : 20.0f);
        seekThumbPx = dp(category >= LARGE_PHONE ? 13.0f : 12.0f);
        segmentedHeightPx = dp(category == SMALL_PHONE ? 30.0f : 32.0f);
        segmentedInnerPaddingPx = dp(2.0f);
        segmentedOptionPaddingPx = dp(8.0f);

        int contentWidthPx = Math.max(dp(180.0f), menuWidthPx - sidebarWidthPx - sidebarGapPx - contentPaddingHorizontalPx - dp(18.0f));
        seekLabelWidthPx = Math.min(dp(118.0f), Math.round(contentWidthPx * 0.34f));
        segmentedLabelWidthPx = Math.min(dp(122.0f), Math.round(contentWidthPx * 0.36f));
        valueWidthPx = dp(category == SMALL_PHONE ? 36.0f : 40.0f);
        iconSizePx = dp(category == SMALL_PHONE ? 48.0f : category == TABLET ? 56.0f : 52.0f);

        titleSp = category >= LARGE_PHONE ? 15.0f : 14.0f;
        sidebarSp = category == SMALL_PHONE ? 11.0f : category == NORMAL_PHONE ? 11.5f : 12.0f;
        labelSp = category == SMALL_PHONE ? 11.5f : category == TABLET ? 12.5f : 12.0f;
        sectionSp = category == SMALL_PHONE ? 10.5f : 11.0f;
        valueSp = category == SMALL_PHONE ? 11.5f : 12.0f;
        segmentedSp = category == SMALL_PHONE ? 10.5f : 11.0f;
    }

    int dp(float value) {
        return Math.round(value * density);
    }

    static float clamp(float value, float min, float max) {
        return Math.max(min, Math.min(max, value));
    }
}
