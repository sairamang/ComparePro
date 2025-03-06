#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unistd.h>
class Utils {
    public:
        static void printUsage();
        static bool isFileExists(std::string mFilePath);
        static bool isDirectory(std::string filePath);
        static std::string getCurrentWorkingDirectory();
        static std::vector<std::string> ListCurrentFilesinDirectory(std::string myDirectoryPath);
    private:
        Utils() = default;
        ~Utils() = default;
        static Utils myinstance;
};
