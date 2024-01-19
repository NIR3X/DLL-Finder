# DLL Finder - A Simple C++ Program for Finding DLL Files

DLL Finder is a simple C++ program that recursively searches for DLL files on all available drives and writes the results to a file.

## Features

- Searches for DLL files on all logical drives.
- Writes the list of found DLL files to a file named "dlls.txt".
- Provides progress updates during the search.

## How to Use

1. Compile the program on a Windows system.
2. Run the compiled executable.
3. The program will scan all drives, find DLL files, and write the results to "dlls.txt".
4. View the results in the generated "dlls.txt" file.

## Usage Example

```bash
dll_finder.exe
```

## Dependencies

* Windows API

## Compilation

Compile the program using a C++ compiler. For example:

```bash
g++ -std=c++2a -Wall -O2 -march=x86-64 -fno-rtti dll_finder.cpp -o dll_finder.exe -s -static
```
