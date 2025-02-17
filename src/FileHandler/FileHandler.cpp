#include "FileHandler.h"
#include "Comparator.h"

void FileHandler::addFileToCompare(CompareFile myFile) {
    myFiles.push_back(std::move(myFile));
}
void FileHandler::removeFileFromCompare(CompareFile myFile) {
    bool element_found = false;
    int i = 0 ;
    for(i = 0 ; i< myFiles.size(); i++) {
        if (myFiles[i].getFileId() == myFile.getFileId()) {
            element_found = true;
            break;
        } 
    }
    if (true == element_found) {
        myFiles.erase(myFiles.begin() + i);
    }
}

void FileHandler::compareListOfFiles() {
    for (int i =0 ;i < myFiles.size();i++) {
        for (int j = i+1 ; j< myFiles.size();j++) {
            Comparator::compare(myFiles[i], myFiles[j]); 
        }
    }
}
void FileHandler::getListOfFiles(std::vector<CompareFile>& myFiles) {
    myFiles = this->myFiles;
}