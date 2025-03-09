#include <iostream>
#include "Utils.h"
#include "CompareFile.h"
#include "Comparator.h"
#include "FileHandler.h"
#include "FileDisplay.h"
#include "FileDisplay.h"
bool check_input_arguments(int argc, char **argv)
{
    if (argc > 1)
    {
        if (argc <= 2)
        {
            std::cout << "Too few arguments" << std::endl;
            Utils::printUsage();
            return false;
        }

        std::string myFile1(argv[1]);
        std::string myFile2(argv[2]);

        if (!Utils::isFileExists(myFile1))
        {
            std::cout << "File does not exists" << myFile1 << std::endl;
            return false;
        }

        if (!Utils::isFileExists(myFile2))
        {
            std::cout << "File does not exists" << myFile2 << std::endl;
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    if (!check_input_arguments(argc, argv)) {
        return 0;
    }
    FileDisplay myFileDisplay({720, 640});
    myFileDisplay.start();
    myFileDisplay.stop();
    return 0;
}