# C++ Systems Programming & Reverse Engineering

This repository contains clean-room reimplementations of three fundamental C++ systems libraries,
demonstrating applied reverse engineering, low-level systems programming, and behavioral validation.

Starting exclusively from compiled, stripped DLL binaries with no source code, header files, or
technical specifications provided, I reconstructed the undocumented API surface, underlying data
structures, memory layouts, and behavioral edge cases for each library. The final deliverable is
a fully functional C++ implementation built from scratch that acts as a drop-in replacement for
the original reference binaries.

---

## Tools & Methodology

A black-box analysis approach was used to recover system architecture directly from compiled binaries:

- **Static Analysis & Disassembly:** Used Ghidra to disassemble x86/x64 binaries, inspect control
  flow graphs (CFGs), and trace execution paths to reconstruct underlying logic with no source
  reference.
- **Calling Convention Recovery:** Identified undocumented `__fastcall`, `__thiscall`, and
  `__stdcall` conventions, recovering function signatures, argument registers, and stack layouts
  from raw assembly.
- **Memory & Data Structure Reconstruction:** Recovered object memory layouts, vtables, struct
  padding, and alignment requirements by analyzing memory access patterns and instruction operands
  in the disassembly.
- **Behavioral Validation:** Developed test suites to validate each C++ implementation against the
  reference DLLs, verifying identical runtime behavior, error propagation paths, and memory states
  across all edge cases.

---

## Reimplemented Libraries

### Math Library (`/Math`)

A high-performance C++ mathematics library for 3D graphics and game engine development. Reversing
the binary revealed optimized implementations of vectors, matrices, and quaternions, including
complex spatial transformations and SIMD-friendly memory alignment considerations recovered from
instruction-level analysis.

### Parent-Child-Sibling Tree (`/PCSTree`)

A hierarchical data structure library implementing a Parent-Child-Sibling (PCS) tree. The reverse
engineering process required mapping node linkage strategies, traversal algorithms, and
insertion/removal mechanics from heavily optimized compiled output with no debug symbols.

### Virtual File System (`/File`)

A low-level file I/O and virtual file system library. Analysis involved recovering internal file
handle state management, custom error propagation paths, and archive packing format structure
through control flow tracing and memory access pattern analysis of the reference binary.

---

## Repository Structure

- `/Math` — C++ implementation of the mathematics library
- `/PCSTree` — C++ implementation of the PCS tree data structure
- `/File` — C++ implementation of the virtual file system
- `/_GivenDlls` — Original compiled reference binaries used exclusively as analysis targets.
  No source code is available for these; they served purely as black-box inputs to the
  reverse engineering process.
- `UberCleanAll.Bat` — Utility script for cleaning build artifacts and intermediate files

---

## Skills Demonstrated

- x86/x64 disassembly and control flow analysis using Ghidra
- Calling convention identification and vtable reconstruction from stripped binaries
- Memory layout and data structure recovery from assembly-level analysis
- Behavioral validation of C++ implementations against reference binaries
- Low-level C++ systems programming: memory layout, RAII, custom allocators, struct alignment

---

*This repository is intended to demonstrate reverse engineering methodology, x86/x64 assembly
comprehension, and C++ systems programming capability.*
