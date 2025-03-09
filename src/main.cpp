#include <iostream>
#include "Utils.h"
#include "CompareFile.h"
#include "Comparator.h"
#include "FileHandler.h"
#include "FileDisplay.h"
#include "FileDisplay.h"
#include "common_def.h"
bool check_input_arguments(int argc, char **argv)
{
    if (argc > 1)
    {
        if (argc <= 2)
        {
            std::cout << "Too few arguments" << std::endl;
            Utils::printUsage();
            return RETURN_CODES::E_NOK;
        }

        std::string myFile1(argv[1]);
        std::string myFile2(argv[2]);

        if (!Utils::isFileExists(myFile1))
        {
            std::cout << "File does not exists" << myFile1 << std::endl;
            return RETURN_CODES::E_NOK;
        }

        if (!Utils::isFileExists(myFile2))
        {
            std::cout << "File does not exists" << myFile2 << std::endl;
            return RETURN_CODES::E_NOK;
        }
    }
    return RETURN_CODES::E_OK;
}
int main(int argc, char **argv)
{
    if (!check_input_arguments(argc, argv)) {
        return RETURN_CODES::E_NOK;
    }
    FileDisplay myFileDisplay({720, 640});
    myFileDisplay.start();
    myFileDisplay.stop();
    return RETURN_CODES::E_OK;
}