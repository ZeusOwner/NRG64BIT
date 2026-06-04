package com.bearmod;

import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

final class SidebarMenuController {
    interface PageRenderer {
        void render(LinearLayout parent);
    }

    interface HideMenuCallback {
        void onHideMenu();
    }

    private static final class MenuPage {
        final String id;
        final LanguageKey titleKey;
        final PageRenderer renderer;
        boolean rendered;
        ScrollView scrollView;
        LinearLayout contentRoot;

        MenuPage(String id, LanguageKey titleKey, PageRenderer renderer) {
            this.id = id;
            this.titleKey = titleKey;
            this.renderer = renderer;
        }
    }

    private static final class SidebarButton {
        final String id;
        final LinearLayout root;
        final TextView label;
        final View indicator;

        SidebarButton(String id, LinearLayout root, TextView label, View indicator) {
            this.id = id;
            this.root = root;
            this.label = label;
            this.indicator = indicator;
        }
    }

    private final Floating owner;
    private final UIDimensions dims;
    private final OverlayComponentFactory components;
    private final HideMenuCallback hideMenuCallback;
    private final Map<String, MenuPage> menuPageMap = new HashMap<>();
    private final Map<String, SidebarButton> sidebarButtonMap = new HashMap<>();
    private final List<String> menuPageOrder = new ArrayList<>();

    private RelativeLayout pageHost;
    private LinearLayout sidebarContainer;
    private String currentPageId;

    SidebarMenuController(Floating owner, UIDimensions dims, OverlayComponentFactory components, HideMenuCallback hideMenuCallback) {
        this.owner = owner;
        this.dims = dims;
        this.components = components;
        this.hideMenuCallback = hideMenuCallback;
    }

    void registerPage(String id, LanguageKey titleKey, PageRenderer renderer) {
        MenuPage page = new MenuPage(id, titleKey, renderer);
        menuPageMap.put(id, page);
        menuPageOrder.add(id);
    }

    void build(LinearLayout root, String initialPageId, View.OnTouchListener dragListener) {
        currentPageId = null;

        root.setPadding(0, 0, 0, 0);
        root.setBackground(components.roundedStrokeBg(Floating.PANEL_BG, Floating.PANEL_BORDER, 1, 8));

        TextView titleView = components.createText("BEAR-MOD", dims.titleSp, Floating.TEXT_PRIMARY, Gravity.CENTER);
        titleView.setSingleLine(true);
        titleView.setOnTouchListener(dragListener);
        root.addView(titleView, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dims.headerHeightPx));

        LinearLayout contentRow = new LinearLayout(owner);
        contentRow.setOrientation(LinearLayout.HORIZONTAL);
        contentRow.setPadding(dims.contentPaddingHorizontalPx, 0, dims.contentPaddingHorizontalPx, dims.contentPaddingBottomPx);
        root.addView(contentRow, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 0, 1));

        sidebarContainer = new LinearLayout(owner);
        sidebarContainer.setOrientation(LinearLayout.VERTICAL);
        sidebarContainer.setPadding(dims.sidebarPaddingPx, dims.sidebarPaddingPx, dims.sidebarPaddingPx, dims.sidebarPaddingPx);
        sidebarContainer.setBackground(components.roundedStrokeBg(Floating.SIDEBAR_BG, Floating.PANEL_BORDER, 1, 6));
        LinearLayout.LayoutParams sidebarParams = new LinearLayout.LayoutParams(dims.sidebarWidthPx, ViewGroup.LayoutParams.MATCH_PARENT);
        sidebarParams.setMargins(0, 0, dims.sidebarGapPx, 0);
        contentRow.addView(sidebarContainer, sidebarParams);

        pageHost = new RelativeLayout(owner);
        contentRow.addView(pageHost, new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.MATCH_PARENT, 1));

        for (String pageId : menuPageOrder) {
            addSidebarButton(pageId, menuPageMap.get(pageId).titleKey);
        }
        View sidebarFill = new View(owner);
        sidebarContainer.addView(sidebarFill, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 0, 1));
        addHideMenuButton();

        selectPage(menuPageMap.containsKey(initialPageId) ? initialPageId : Floating.PAGE_MAIN);
    }

    String getCurrentPageId() {
        return currentPageId;
    }

    void selectPage(String id) {
        MenuPage nextPage = menuPageMap.get(id);
        if (nextPage == null || pageHost == null) {
            return;
        }
        if (currentPageId != null) {
            MenuPage currentPage = menuPageMap.get(currentPageId);
            if (currentPage != null && currentPage.scrollView != null) {
                currentPage.scrollView.setVisibility(View.GONE);
            }
        }
        ensurePageRendered(nextPage);
        nextPage.scrollView.setVisibility(View.VISIBLE);
        currentPageId = id;
        updateSidebarState(id);
    }

    private void addSidebarButton(final String id, LanguageKey labelKey) {
        final LinearLayout button = new LinearLayout(owner);
        button.setOrientation(LinearLayout.HORIZONTAL);
        button.setGravity(Gravity.CENTER);
        button.setPadding(dims.contentPaddingHorizontalPx, 0, dims.contentPaddingHorizontalPx, 0);
        button.setBackground(sidebarButtonBg(false));
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dims.sidebarButtonHeightPx);
        params.setMargins(0, 0, 0, dims.sidebarButtonSpacingPx);
        sidebarContainer.addView(button, params);

        TextView label = components.createBoundText(labelKey, dims.sidebarSp, Floating.TEXT_SECONDARY, Gravity.CENTER);
        components.compactSingleLine(label);
        button.addView(label, new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.MATCH_PARENT, 1));

        View indicator = new View(owner);
        indicator.setBackground(components.roundedBg(Floating.ACCENT_GREEN, 2));
        indicator.setVisibility(View.INVISIBLE);
        LinearLayout.LayoutParams indicatorParams = new LinearLayout.LayoutParams(dims.sidebarIndicatorWidthPx, dims.sidebarIndicatorHeightPx);
        button.addView(indicator, indicatorParams);

        sidebarButtonMap.put(id, new SidebarButton(id, button, label, indicator));
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                selectPage(id);
            }
        });
    }

    private void addHideMenuButton() {
        LinearLayout button = new LinearLayout(owner);
        button.setOrientation(LinearLayout.HORIZONTAL);
        button.setGravity(Gravity.CENTER);
        button.setPadding(dims.contentPaddingHorizontalPx, 0, dims.contentPaddingHorizontalPx, 0);
        button.setBackground(sidebarButtonBg(false));
        sidebarContainer.addView(button, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dims.sidebarButtonHeightPx));

        TextView label = components.createBoundText(LanguageKey.BUTTON_HIDE_MENU, dims.sidebarSp, Floating.TEXT_PRIMARY, Gravity.CENTER);
        components.compactSingleLine(label);
        button.addView(label, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                hideMenuCallback.onHideMenu();
            }
        });
    }

    private void ensurePageRendered(MenuPage page) {
        if (page.rendered) {
            return;
        }
        page.scrollView = new ScrollView(owner);
        page.scrollView.setFillViewport(false);
        page.scrollView.setOverScrollMode(View.OVER_SCROLL_IF_CONTENT_SCROLLS);
        page.scrollView.setVisibility(View.GONE);

        page.contentRoot = new LinearLayout(owner);
        page.contentRoot.setOrientation(LinearLayout.VERTICAL);
        page.contentRoot.setPadding(0, 0, 0, dims.contentPaddingBottomPx);
        page.scrollView.addView(page.contentRoot, new ScrollView.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        pageHost.addView(page.scrollView, new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        page.renderer.render(page.contentRoot);
        page.rendered = true;
    }

    private void updateSidebarState(String activeId) {
        for (Map.Entry<String, SidebarButton> entry : sidebarButtonMap.entrySet()) {
            boolean active = activeId.equals(entry.getKey());
            SidebarButton button = entry.getValue();
            button.root.setBackground(sidebarButtonBg(active));
            button.label.setTextColor(active ? Floating.TEXT_PRIMARY : Floating.TEXT_SECONDARY);
            button.indicator.setVisibility(active ? View.VISIBLE : View.INVISIBLE);
        }
    }

    private android.graphics.drawable.Drawable sidebarButtonBg(boolean active) {
        return components.sidebarButtonBg(active, Floating.SIDEBAR_BG, Floating.SIDEBAR_ACTIVE_BG, Floating.PANEL_BORDER);
    }
}
