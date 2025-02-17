#pragma once 
#include <iostream>
#include <string>
class Utils {
    public:
        static void printUsage();
        static bool isFileExists(std::string mFilePath);
    private:
        Utils() = default;
        ~Utils() = default;
        static Utils myinstance;
};
