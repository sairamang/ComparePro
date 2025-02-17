#include "Utils.h"
#include <filesystem>
Utils Utils::myinstance;

void Utils::printUsage() {
    std::cout<<"Usage : ./comparepro [Options] file1 file2"<<std::endl;
}

bool Utils::isFileExists(std::string mFilePath) {
    return std::filesystem::is_regular_file(mFilePath);
}