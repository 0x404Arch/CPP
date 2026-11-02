# C++/CPP
This repository is dedicated to learning and practicing C++ fundamentals, OOP concepts in C++, Data Structures & Algorithms (DSA), and competitive programming.

It includes:
- C++ basics and core concepts
- OOP in C++
- Data Structures & Algorithms
- Problem-solving practice
- Competitive Programming (CP)
- Coding challenges from platforms like LeetCode.

## Building and running

Build and run the C++ learning program:

```bash
./scripts/run.sh         # Build and run
./scripts/run.sh build   # Build only
./scripts/run.sh debug   # Build with debug symbols
./scripts/run.sh clean
```

The CMake target is `cpp_learning`, and build outputs go under `build/`. Install CMake and GCC with C++17 support first; some examples use GCC's `<bits/stdc++.h>` header.

## Debugging in VS Code (macOS)

Install the **CodeLLDB** extension (`vadimcn.vscode-lldb`) and open this repository as the VS Code workspace. Choose **Debug cpp-learning (LLDB)** from the Run and Debug menu. The configuration builds the program with debug symbols before launching it. Set breakpoints in the source files before starting the debugger.

The script prefers Homebrew GCC (`g++-16`) when available. You can also create a debug build from a terminal with `./scripts/run.sh debug`.

---