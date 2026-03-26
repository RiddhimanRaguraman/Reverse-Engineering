# C++ Systems Programming & Reverse Engineering

This repository contains clean-room reimplementations of three fundamental C++ systems libraries. The project demonstrates applied reverse engineering, systems programming, and behavioral validation. 

Starting exclusively from compiled, stripped DLL binaries with no source code, header files, or technical specifications provided, I reconstructed the undocumented API surface, underlying data structures, memory layouts, and behavioral edge cases for each library. The final deliverable is a fully functional C++ implementation built from scratch that acts as a drop-in replacement for the original binaries.

## 🛠 Tools & Methodology

This project utilized a black-box analysis approach to recover system architecture from compiled binaries:

- **Static Analysis & Disassembly:** Used **Ghidra** to disassemble x86/x64 binaries, inspect control flow graphs (CFGs), and trace execution paths to understand the underlying logic.
- **Calling Convention Recovery:** Identified undocumented `__fastcall`, `__thiscall`, and `__stdcall` conventions, recovering function signatures, argument registers, and stack layouts.
- **Memory & Data Structure Analysis:** Reconstructed object memory layouts, vtables, struct padding, and alignment requirements from assembly instructions.
- **Behavioral Validation:** Developed comprehensive test suites to validate the newly written C++ implementation against the reference DLLs, ensuring identical runtime behavior, error handling, and memory states.

## 📚 Reimplemented Libraries

### 1. Math Library (`/Math`)
A high-performance C++ mathematics library tailored for 3D graphics and game engine development. Reversing the binary revealed optimized implementations for Vectors, Matrices, and Quaternions, including complex transformations and SIMD-friendly memory alignment considerations.

### 2. Parent-Child-Sibling Tree (`/PCSTree`)
A hierarchical data structure library implementing a Parent-Child-Sibling (PCS) tree. The reverse engineering process required mapping out node linkage, tree traversal algorithms, and insertion/removal mechanics, which were heavily optimized in the original binary.

### 3. Virtual File System (`/File`)
A low-level file I/O wrapper and virtual file system. Analysis of the original DLL involved tracing system calls (like `CreateFile`, `ReadFile`, `WriteFile`) and recovering the error-handling routines and internal state management used to safely handle file handles.

## 🗄 Repository Structure

- `/Math` — C++ implementation of the mathematics library.
- `/PCSTree` — C++ implementation of the PCS tree data structure.
- `/File` — C++ implementation of the virtual file system.
- `/_GivenDlls` — Contains the original compiled reference binaries used exclusively as analysis targets. *(Note: These are provided as black-box targets; no source code is available).*
- `UberCleanAll.Bat` — Utility script for cleaning build artifacts and intermediate files.

---
*Disclaimer: This repository is intended to demonstrate reverse engineering methodologies, x86/x64 assembly comprehension, and C++ systems programming capabilities.*
