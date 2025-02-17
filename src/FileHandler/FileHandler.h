#pragma once 
#include <fstream>
#include <vector>

#include "CompareFile.h"
class FileHandler {
    public:
        FileHandler() = default;
        void addFileToCompare(CompareFile myFile);
        void removeFileFromCompare(CompareFile myFile);
        void compareListOfFiles();
        void getListOfFiles(std::vector<CompareFile>& myFiles);
    private:
        std::vector<CompareFile> myFiles;
};