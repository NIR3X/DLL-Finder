#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void FindDllFiles(const std::string& directory, std::vector<std::string>& dllFiles) {
	WIN32_FIND_DATAA findFileData;
	HANDLE hFind = FindFirstFileA((directory + "\\*").c_str(), &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		// std::cerr << "Error finding files in directory: " << directory << std::endl;
		return;
	}

	do {
		if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
				FindDllFiles(directory + "\\" + findFileData.cFileName, dllFiles);
			}
		} else {
			size_t len = strlen(findFileData.cFileName);
			if (len >= 4 && stricmp(findFileData.cFileName + len - 4, ".dll") == 0) {
				dllFiles.push_back(directory + "\\" + findFileData.cFileName);
				printf("\rFound %lld DLLs", (long long)dllFiles.size());
			}
		}
	} while (FindNextFileA(hFind, &findFileData) != 0);

	FindClose(hFind);
}

void FindDllFilesOnAllDrives(std::vector<std::string>& dllFiles) {
	DWORD drives = GetLogicalDrives();
	for (char drive = 'A'; drive <= 'Z'; ++drive) {
		if ((drives & (1 << (drive - 'A'))) != 0) {
			std::string drivePath = "";
			drivePath += drive;
			drivePath += ":";
			FindDllFiles(drivePath, dllFiles);
		}
	}
}

void WriteDllListToFile(const std::vector<std::string>& dllFiles, const std::string& fileName) {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}

	for (const auto& dllFile : dllFiles) {
		outFile << dllFile << std::endl;
	}

	outFile.close();
}

int main() {
	std::vector<std::string> dllFiles = {};
	FindDllFilesOnAllDrives(dllFiles);
	WriteDllListToFile(dllFiles, "dlls.txt");
	std::cout << std::endl << "Found DLLs written to dlls.txt" << std::endl;
	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();
}
