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
DllFinder.exe
```

## Dependencies

* Windows API

## Compilation

Compile the program using a C++ compiler. For example:

```bash
g++ -std=c++2a -Wall -O2 -march=x86-64 -fno-rtti DllFinder.cpp -o DllFinder.exe -s -static
```

## License

[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
