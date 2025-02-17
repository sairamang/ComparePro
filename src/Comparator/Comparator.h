#pragma once 
#include "CompareFile.h"
class Comparator {
    public:
        static bool compare(CompareFile file1, CompareFile file2);
    private:
        Comparator()= default;
        ~Comparator()= default;
};