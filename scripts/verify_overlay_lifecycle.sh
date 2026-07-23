#!/usr/bin/env bash
set -euo pipefail

project_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
java_root="$project_root/app/src/main/java/com/bearmod"
floating="$java_root/Floating.java"
registry="$java_root/OverlayWindowRegistry.java"
update_loop="$java_root/OverlayUpdateLoop.java"
config_manager="$java_root/ConfigManager.java"

for required_file in "$floating" "$registry" "$update_loop" "$config_manager"; do
    if [[ ! -f "$required_file" ]]; then
        echo "Missing lifecycle source: $required_file" >&2
        exit 1
    fi
done

if grep -Eq 'windowManager\.(addView|removeView|removeViewImmediate|updateViewLayout)\(' "$floating"; then
    echo "Floating.java bypasses OverlayWindowRegistry" >&2
    exit 1
fi

if grep -Eq 'windowManager\.updateViewLayout\(' "$java_root/RecorderFakeUtils.java"; then
    echo "RecorderFakeUtils.java bypasses OverlayWindowRegistry" >&2
    exit 1
fi

stop_line="$(grep -n 'overlayUpdateLoop.stop()' "$floating" | head -1 | cut -d: -f1)"
shutdown_line="$(grep -n 'overlayWindowRegistry.shutdown()' "$floating" | head -1 | cut -d: -f1)"
if [[ -z "$stop_line" || -z "$shutdown_line" || "$stop_line" -ge "$shutdown_line" ]]; then
    echo "Floating.onDestroy() must stop updates before removing overlay windows" >&2
    exit 1
fi

grep -q 'scheduler == null || scheduler.isShutdown()' "$config_manager"
grep -q 'persist(targetPrefs, snapshot, true)' "$config_manager"
grep -q '^\.gradle/$' "$project_root/.gitignore"
grep -q '^local\.properties$' "$project_root/.gitignore"

echo "Overlay lifecycle source contract: PASS"
