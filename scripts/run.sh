#!/bin/bash
#
# Usage:
#   ./scripts/run.sh [run|build|debug|clean]

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

MODE="run"

case "${1:-}" in
    "")
        ;;
    build|debug|run|clean)
        MODE="$1"
        ;;
    *)
        echo "Unknown mode: $1" >&2
        echo "Usage: $0 [run|build|debug|clean]" >&2
        exit 2
        ;;
esac

BUILD_DIR="$ROOT/build"
TARGET="cpp_learning"
EXECUTABLE="$BUILD_DIR/$TARGET"

configure() {
    if ! command -v cmake >/dev/null 2>&1; then
        echo "CMake is required. Install it with: brew install cmake" >&2
        exit 127
    fi

    local compiler=""
    if command -v g++-16 >/dev/null 2>&1; then
        compiler="$(command -v g++-16)"
    elif command -v g++ >/dev/null 2>&1; then
        compiler="$(command -v g++)"
    fi

    if [[ -n "$compiler" ]] && ! "$compiler" -v 2>&1 | grep -q 'gcc version'; then
        compiler=""
    fi

    if [[ -z "$compiler" ]]; then
        echo "GCC is required because the examples use <bits/stdc++.h>. Install it with: brew install gcc" >&2
        exit 1
    fi

    cmake -S "$ROOT" -B "$BUILD_DIR" \
        -DCMAKE_CXX_COMPILER="$compiler" \
        -DCMAKE_BUILD_TYPE="$([[ "$MODE" == "debug" ]] && echo Debug || echo Release)"
}

case "$MODE" in
    build|debug|run)
        configure
        cmake --build "$BUILD_DIR" --target "$TARGET" --parallel
        if [[ "$MODE" == "run" ]]; then
            echo "Running cpp-learning"
            echo "---"
            "$EXECUTABLE"
        fi
        ;;
    clean)
        if [[ -f "$BUILD_DIR/CMakeCache.txt" ]]; then
            cmake --build "$BUILD_DIR" --target clean
        else
            echo "Nothing to clean for CMake builds."
        fi
        ;;
    *)
        echo "Unknown mode: $MODE" >&2
        echo "Usage: $0 [run|build|debug|clean]" >&2
        exit 2
        ;;
esac