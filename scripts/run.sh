#!/bin/bash
#
# Usage:
#   ./scripts/run.sh [run|build|debug|clean]
#
# Description:
#   Configures the CMake project, builds the target, and optionally
#   runs the compiled executable.
# ------------------------------------------------------------------ #

# Exit immediately if a command fails, an undefined variable is used, 
# or a command in a pipeline fails.
set -euo pipefail

# Resolve project root and switch to it
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

# Default mode is run
MODE="run"

# Parse the requested execution mode
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

# Detect dependencies and configure the CMake project
configure() {
    if ! command -v cmake >/dev/null 2>&1; then
        echo "CMake is required. Install it with: brew install cmake" >&2
        exit 127
    fi

    # Prefer GCC 16, falling back to the default GCC installation
    local compiler=""
    if command -v g++-16 >/dev/null 2>&1; then
        compiler="$(command -v g++-16)"
    elif command -v g++ >/dev/null 2>&1; then
        compiler="$(command -v g++)"
    fi

    # Ensure the selected compiler is GCC, not Clang
    if [[ -n "$compiler" ]] && ! "$compiler" -v 2>&1 | grep -q 'gcc version'; then
        compiler=""
    fi

    if [[ -z "$compiler" ]]; then
        echo "GCC is required because the examples use <bits/stdc++.h>. Install it with: brew install gcc" >&2
        exit 1
    fi

    # Use Debug configuration only for debug mode; otherwise use Release
    cmake -S "$ROOT" -B "$BUILD_DIR" \
        -DCMAKE_CXX_COMPILER="$compiler" \
        -DCMAKE_BUILD_TYPE="$([[ "$MODE" == "debug" ]] && echo Debug || echo Release)"
}

# Configure and build the project; run the executable when requested
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
    
    # Clean generated build artifacts
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