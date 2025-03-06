#include <iostream>
#include "Utils.h"
#include "CompareFile.h"
#include "Comparator.h"
#include "FileHandler.h"
#include "FileDisplay.h"
#include "FileDisplay.h"
int main(int argc, char** argv) {
    if (argc <=2) {
        std::cout<<"Too few arguments"<<std::endl;
        Utils::printUsage();
        Utils::printUsage();
        return 0;
    }

    std::string myFile1(argv[1]);
    std::string myFile2(argv[2]);

    if (!Utils::isFileExists(myFile1)) {
        std::cout<<"File does not exists"<<myFile1<<std::endl;
        return 0;
    }

    if (!Utils::isFileExists(myFile2)) {
        std::cout<<"File does not exists"<<myFile2<<std::endl;
        return 0;
    }

    CompareFile cmpfile1  = CompareFile(myFile1);
    CompareFile cmpfile2 = CompareFile(myFile2);

    FileHandler myFileHandler;
    
    myFileHandler.addFileToCompare(cmpfile1);
    myFileHandler.addFileToCompare(cmpfile2);

    myFileHandler.compareListOfFiles();

    FileDisplay myFileDisplay({720,640});
    myFileDisplay.start();
    myFileDisplay.stop();
    return 0;
}