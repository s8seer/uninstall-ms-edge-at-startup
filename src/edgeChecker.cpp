#include <iostream>
#include <cmath>
#include <windows.h>
#include <shellapi.h>
#include <tchar.h>

#include "edgeStuff.h"

std::filesystem::path cwd = std::filesystem::current_path();
std::string stringpath = cwd.generic_string();

int main(){
	for (int i = 0; i < size(edgeDirectories); i++){
		if (checkDirectory(edgeDirectories[i])){
			ShellExecute(NULL, _T("open"), _T("edgeUninstaller.exe"), NULL, NULL, SW_SHOWNORMAL);
			return 0;
		}
	}
	return 0;
}