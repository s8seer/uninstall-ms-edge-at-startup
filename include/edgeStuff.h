#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <filesystem>

// Required for std::replace
#include <algorithm>

#include "logging.h"

std::string userDir = getenv("USERPROFILE");
std::error_code errorCode;

std::string edgeDirectories[] = {
    "C:/Program Files (x86)/Microsoft/EdgeWebView",
    "C:/Program Files (x86)/Microsoft/EdgeUpdate",
    "C:/Program Files (x86)/Microsoft/EdgeCore",
    "C:/Program Files (x86)/Microsoft/Edge",
    userDir + "/Appdata/Local/Microsoft/Edge",
    userDir + "/Appdata/Roaming/Microsoft/Windows/Start Menu/Programs/Microsoft Edge.lnk"
    
};

bool checkDirectory(std::string dir){ 
    // Structure which would store the metadata
    struct stat sb;

    const char *cdir = dir.c_str();
 
    // Calls the function with path as argument
    // If the file/directory exists at the path returns 0
    // If block executes if path exists
    if (stat(cdir, &sb) == 0) return true;
        
    return false;
};

void deleteDirectory(std::string dir){
    
    if (!std::filesystem::remove_all(dir, errorCode)) {
        std::cout << errorCode.message() << std::endl;
    } else{
        std::replace( dir.begin(), dir.end(), '\\', '/');
        log("File '" + dir + "' found, deleting...");
    }
};