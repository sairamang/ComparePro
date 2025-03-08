#include "Utils.h"
#include <filesystem>
Utils Utils::myinstance;

void Utils::printUsage() {
    std::cout<<"Usage : ./comparepro [Options] file1 file2"<<std::endl;
}

bool Utils::isFileExists(std::string mFilePath) {
    return std::filesystem::is_regular_file(mFilePath);
}
std::string Utils::getCurrentWorkingDirectory() {
    char buffer[300];
    std::string curr_working_dir;
    if (getcwd(buffer,300)!= NULL) {
        std::cout<<"Current working dir"<<curr_working_dir<<std::endl;
        curr_working_dir = buffer;
    }
    return curr_working_dir;
}
bool Utils::isDirectory(std::string filePath) {
    return std::filesystem::is_directory(filePath);
}

std::vector<std::string> Utils::ListCurrentFilesinDirectory(std::string directoryPath) {
    std::vector<std::string> myvec;
    if (std::filesystem::is_directory(directoryPath))
    {
        std::cout<<"Directory Exists"<<std::endl;
        for (auto& entry: std::filesystem::directory_iterator(directoryPath)) {
            myvec.push_back(entry.path());
        }         

        for (auto& it: myvec) {
            it.erase(0,directoryPath.length());
            std::cout<<"list entry :"<<it<<std::endl;
        }
        return myvec;    
    }
    return myvec;
}