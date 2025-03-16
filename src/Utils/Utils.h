#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <unistd.h>
class Utils {
    public:
        static void printUsage();
        static bool isFileExists(std::string mFilePath);
        static bool isDirectory(std::string filePath);
        static std::string getCurrentWorkingDirectory();
        static std::vector<std::string> ListCurrentFilesinDirectory(std::string myDirectoryPath);
        static std::string sanitizeCurrWorkingDirectory(std::string currWorkingDir);
    private:
        static void split_path_by_folders(std::string& path, std::vector<std::string>& temp_str_array);
        static void filter_out_double_dot(std::vector<std::string>& temp_string_array, std::stack<std::string>& my_stack);
        static void form_final_str_from_stack(std::stack<std::string>& my_stack, std::string& final_path);
        Utils() = default;
        ~Utils() = default;
        static Utils myinstance;
};
