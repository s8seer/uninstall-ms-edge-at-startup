#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>    

 
std::string currentDateTime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
 
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", now);
    return buffer;
}

void log(std::string message)
{
    std::ofstream of;

    std::string output = "[" + currentDateTime() + "]: " + message + "\n";
   
    // opening file using ofstream
    of.open("./log.txt", std::ios::app);
    if (!of)
        std::cout << "File creation error";
    else {
        of << output;
        of.close();
    }
}