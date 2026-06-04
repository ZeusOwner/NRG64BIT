package com.bearmod;

import android.content.Context;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.text.TextUtils;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;

final class OverlayComponentFactory {
    private final Context context;
    private UIDimensions dims;

    OverlayComponentFactory(Context context, UIDimensions dims) {
        this.context = context;
        this.dims = dims;
    }

    void setDimensions(UIDimensions dims) {
        this.dims = dims;
    }

    GradientDrawable roundedBg(int color, float radiusDp) {
        GradientDrawable drawable = new GradientDrawable();
        drawable.setColor(color);
        drawable.setCornerRadius(dp(radiusDp));
        return drawable;
    }

    GradientDrawable roundedStrokeBg(int fill, int stroke, int strokeDp, float radiusDp) {
        GradientDrawable drawable = roundedBg(fill, radiusDp);
        drawable.setStroke(dp(strokeDp), stroke);
        return drawable;
    }

    Drawable sidebarButtonBg(boolean active, int sidebarBg, int activeBg, int borderColor) {
        return roundedStrokeBg(active ? activeBg : sidebarBg, borderColor, 1, 4);
    }

    View sectionDivider(int dividerColor) {
        View lineView = new View(context);
        lineView.setBackgroundColor(dividerColor);
        LinearLayout.LayoutParams lineParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, Math.max(1, dp(0.5f)));
        lineParams.setMargins(0, dims.dividerMarginTopPx, 0, dims.dividerMarginBottomPx);
        lineView.setLayoutParams(lineParams);
        return lineView;
    }

    Drawable switchThumbDrawable() {
        GradientDrawable drawable = new GradientDrawable();
        drawable.setShape(GradientDrawable.OVAL);
        drawable.setSize(dims.switchThumbPx, dims.switchThumbPx);
        drawable.setColor(Color.rgb(245, 245, 245));
        return drawable;
    }

    Drawable switchTrackDrawable(int switchOn, int switchOff) {
        GradientDrawable drawable = new GradientDrawable();
        drawable.setShape(GradientDrawable.RECTANGLE);
        drawable.setCornerRadius(dims.switchHeightPx / 2.0f);
        drawable.setSize(dims.switchWidthPx, dims.switchHeightPx);
        if (Build.VERSION.SDK_INT >= 21) {
            ColorStateList colors = new ColorStateList(
                new int[][]{new int[]{android.R.attr.state_checked}, new int[]{-android.R.attr.state_checked}},
                new int[]{switchOn, switchOff}
            );
            drawable.setColor(colors);
        } else {
            drawable.setColor(switchOff);
        }
        return drawable;
    }

    TextView createText(String text, float sp, int color, int gravity) {
        TextView textView = new TextView(context);
        textView.setText(text);
        textView.setTextSize(TypedValue.COMPLEX_UNIT_SP, sp);
        textView.setTextColor(color);
        textView.setGravity(gravity);
        textView.setIncludeFontPadding(false);
        return textView;
    }

    TextView createBoundText(LanguageKey key, float sp, int color, int gravity) {
        TextView textView = createText(LanguageManager.getInstance().getString(key), sp, color, gravity);
        LanguageManager.getInstance().bind(textView, key);
        return textView;
    }

    void compactSingleLine(TextView textView) {
        textView.setSingleLine(true);
        textView.setEllipsize(TextUtils.TruncateAt.END);
    }

    void addSectionTitle(String label, LinearLayout parent, int textSecondary) {
        TextView textView = createText(label, dims.sectionSp, textSecondary, Gravity.START | Gravity.CENTER_VERTICAL);
        textView.setPadding(0, dims.contentPaddingBottomPx, 0, dims.dividerMarginTopPx);
        textView.setTypeface(android.graphics.Typeface.DEFAULT_BOLD);
        parent.addView(textView, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
    }

    void addSectionTitle(LanguageKey key, LinearLayout parent, int textSecondary) {
        TextView textView = createBoundText(key, dims.sectionSp, textSecondary, Gravity.START | Gravity.CENTER_VERTICAL);
        textView.setPadding(0, dims.contentPaddingBottomPx, 0, dims.dividerMarginTopPx);
        textView.setTypeface(android.graphics.Typeface.DEFAULT_BOLD);
        parent.addView(textView, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
    }

    CompoundButton addToggleRow(String label, boolean checked, CompoundButton.OnCheckedChangeListener listener, LinearLayout parent, int textPrimary, int switchOn, int switchOff, int divider) {
        return addToggleRowInternal(label, null, checked, listener, parent, textPrimary, switchOn, switchOff, divider);
    }

    CompoundButton addToggleRow(LanguageKey labelKey, boolean checked, CompoundButton.OnCheckedChangeListener listener, LinearLayout parent, int textPrimary, int switchOn, int switchOff, int divider) {
        return addToggleRowInternal(null, labelKey, checked, listener, parent, textPrimary, switchOn, switchOff, divider);
    }

    private CompoundButton addToggleRowInternal(String label, LanguageKey labelKey, boolean checked, CompoundButton.OnCheckedChangeListener listener, LinearLayout parent, int textPrimary, int switchOn, int switchOff, int divider) {
        LinearLayout row = new LinearLayout(context);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setGravity(Gravity.CENTER_VERTICAL);
        row.setPadding(0, dims.rowVerticalPaddingPx, dims.segmentedInnerPaddingPx, dims.rowVerticalPaddingPx);
        parent.addView(row, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dims.toggleRowHeightPx));

        TextView labelView = labelKey != null
                ? createBoundText(labelKey, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL)
                : createText(label, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL);
        compactSingleLine(labelView);
        row.addView(labelView, new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.MATCH_PARENT, 1));

        Switch switchView = new Switch(context);
        switchView.setText("");
        switchView.setMinWidth(0);
        switchView.setMinimumWidth(0);
        switchView.setMinHeight(0);
        switchView.setMinimumHeight(0);
        switchView.setPadding(0, 0, 0, 0);
        if (Build.VERSION.SDK_INT >= 21) {
            switchView.setShowText(false);
        }
        switchView.setChecked(checked);
        switchView.setOnCheckedChangeListener(listener);
        switchView.setThumbDrawable(switchThumbDrawable());
        switchView.setTrackDrawable(switchTrackDrawable(switchOn, switchOff));
        LinearLayout.LayoutParams switchParams = new LinearLayout.LayoutParams(dims.switchWidthPx, dims.switchHeightPx + dp(8.0f));
        switchParams.gravity = Gravity.CENTER_VERTICAL;
        row.addView(switchView, switchParams);

        parent.addView(sectionDivider(divider));
        return switchView;
    }

    void addSeekRow(String label, int min, int max, int value, SeekBar.OnSeekBarChangeListener listener, LinearLayout parent, int textPrimary, int textSecondary, int switchOff, int divider) {
        addSeekRowInternal(label, null, min, max, value, listener, parent, textPrimary, textSecondary, switchOff, divider);
    }

    void addSeekRow(LanguageKey labelKey, int min, int max, int value, SeekBar.OnSeekBarChangeListener listener, LinearLayout parent, int textPrimary, int textSecondary, int switchOff, int divider) {
        addSeekRowInternal(null, labelKey, min, max, value, listener, parent, textPrimary, textSecondary, switchOff, divider);
    }

    private void addSeekRowInternal(String label, LanguageKey labelKey, int min, int max, int value, final SeekBar.OnSeekBarChangeListener listener, LinearLayout parent, int textPrimary, int textSecondary, int switchOff, int divider) {
        LinearLayout row = new LinearLayout(context);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setGravity(Gravity.CENTER_VERTICAL);
        row.setPadding(0, dims.rowVerticalPaddingPx, 0, dims.rowVerticalPaddingPx);
        parent.addView(row, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dims.seekRowHeightPx));

        TextView labelView = labelKey != null
                ? createBoundText(labelKey, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL)
                : createText(label, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL);
        compactSingleLine(labelView);
        row.addView(labelView, new LinearLayout.LayoutParams(dims.seekLabelWidthPx, ViewGroup.LayoutParams.MATCH_PARENT));

        final TextView valueView = createText(String.valueOf(value), dims.valueSp, textSecondary, Gravity.CENTER);
        row.addView(valueView, new LinearLayout.LayoutParams(dims.valueWidthPx, ViewGroup.LayoutParams.MATCH_PARENT));

        SeekBar seekBar = new SeekBar(context, null, android.R.attr.seekBarStyle);
        seekBar.setMax(max);
        if (Build.VERSION.SDK_INT >= 26) {
            seekBar.setMin(min);
        }
        int safeValue = value;
        if (safeValue < min) safeValue = min;
        if (safeValue > max) safeValue = max;
        valueView.setText(String.valueOf(safeValue));
        seekBar.setProgress(safeValue);
        if (Build.VERSION.SDK_INT >= 21) {
            GradientDrawable thumbDrawable = new GradientDrawable();
            thumbDrawable.setShape(GradientDrawable.OVAL);
            thumbDrawable.setColor(Color.rgb(238, 238, 238));
            thumbDrawable.setSize(dims.seekThumbPx, dims.seekThumbPx);
            seekBar.setThumb(thumbDrawable);
            seekBar.setProgressTintList(ColorStateList.valueOf(Color.rgb(80, 150, 220)));
            seekBar.setProgressBackgroundTintList(ColorStateList.valueOf(switchOff));
        }
        final int minValue = min;
        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress < minValue) {
                    progress = minValue;
                    seekBar.setProgress(progress);
                }
                valueView.setText(String.valueOf(progress));
                listener.onProgressChanged(seekBar, progress, fromUser);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                listener.onStartTrackingTouch(seekBar);
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                listener.onStopTrackingTouch(seekBar);
            }
        });
        row.addView(seekBar, new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1));

        parent.addView(sectionDivider(divider));
    }

    void addSegmentedRow(String label, String[] options, int selectedIndex, LinearLayout parent, View.OnClickListener[] callbacks, int textPrimary, int textSecondary, int divider) {
        addSegmentedRowInternal(label, null, options, null, selectedIndex, parent, callbacks, textPrimary, textSecondary, divider);
    }

    void addSegmentedRow(LanguageKey labelKey, LanguageKey[] optionKeys, int selectedIndex, LinearLayout parent, View.OnClickListener[] callbacks, int textPrimary, int textSecondary, int divider) {
        String[] options = new String[optionKeys.length];
        for (int i = 0; i < optionKeys.length; i++) {
            options[i] = LanguageManager.getInstance().getString(optionKeys[i]);
        }
        addSegmentedRowInternal(null, labelKey, options, optionKeys, selectedIndex, parent, callbacks, textPrimary, textSecondary, divider);
    }

    private void addSegmentedRowInternal(String label, LanguageKey labelKey, String[] options, LanguageKey[] optionKeys, int selectedIndex, LinearLayout parent, final View.OnClickListener[] callbacks, int textPrimary, int textSecondary, int divider) {
        LinearLayout row = new LinearLayout(context);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setGravity(Gravity.CENTER_VERTICAL);
        row.setPadding(0, dims.rowVerticalPaddingPx + dims.segmentedInnerPaddingPx, 0, dims.rowVerticalPaddingPx + dims.segmentedInnerPaddingPx);
        parent.addView(row, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, Math.max(dims.segmentedRowHeightPx, dims.segmentedHeightPx + (dims.rowVerticalPaddingPx * 4))));

        TextView labelView = labelKey != null
                ? createBoundText(labelKey, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL)
                : createText(label, dims.labelSp, textPrimary, Gravity.START | Gravity.CENTER_VERTICAL);
        compactSingleLine(labelView);
        row.addView(labelView, new LinearLayout.LayoutParams(dims.segmentedLabelWidthPx, ViewGroup.LayoutParams.MATCH_PARENT));

        final TextView[] buttons = new TextView[options.length];
        LinearLayout group = new LinearLayout(context);
        group.setOrientation(LinearLayout.HORIZONTAL);
        group.setGravity(Gravity.CENTER_VERTICAL);
        group.setBackground(roundedBg(Color.rgb(68, 68, 68), 12));
        group.setPadding(dims.segmentedInnerPaddingPx, dims.segmentedInnerPaddingPx, dims.segmentedInnerPaddingPx, dims.segmentedInnerPaddingPx);
        LinearLayout.LayoutParams groupParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, dims.segmentedHeightPx);
        groupParams.gravity = Gravity.CENTER_VERTICAL;
        row.addView(group, groupParams);

        int safeSelected = selectedIndex >= 0 && selectedIndex < options.length ? selectedIndex : 0;
        for (int i = 0; i < options.length; i++) {
            final int index = i;
            TextView option = optionKeys != null && i < optionKeys.length
                    ? createBoundText(optionKeys[i], dims.segmentedSp, index == safeSelected ? Color.BLACK : textSecondary, Gravity.CENTER)
                    : createText(options[i], dims.segmentedSp, index == safeSelected ? Color.BLACK : textSecondary, Gravity.CENTER);
            compactSingleLine(option);
            option.setPadding(dims.segmentedOptionPaddingPx, 0, dims.segmentedOptionPaddingPx, 0);
            option.setBackground(index == safeSelected ? roundedBg(Color.WHITE, 10) : null);
            option.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    for (int j = 0; j < buttons.length; j++) {
                        buttons[j].setTextColor(j == index ? Color.BLACK : textSecondary);
                        buttons[j].setBackground(j == index ? roundedBg(Color.WHITE, 10) : null);
                    }
                    if (callbacks != null && index < callbacks.length && callbacks[index] != null) {
                        callbacks[index].onClick(v);
                    }
                }
            });
            buttons[i] = option;
            group.addView(option, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.MATCH_PARENT));
        }

        parent.addView(sectionDivider(divider));
    }

    int dp(float value) {
        return Math.round(value * context.getResources().getDisplayMetrics().density);
    }
}
