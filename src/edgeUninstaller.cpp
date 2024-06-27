#include <iostream>
#include <cmath>
#include <windows.h>

#include "edgeStuff.h"


std::string str ("Edge");
std::string edgeFilename;

int main(){
    for (int i = 0; i < size(edgeDirectories); i++){
        edgeFilename = (std::filesystem::path(edgeDirectories[i]).filename()).generic_string();

        // This is a safety measure so c++ doesn't accidentally select a parent folder
        if (edgeFilename.find(str) != std::string::npos) {
            deleteDirectory(edgeDirectories[i]);
        }
	}
    
	return 0;
}