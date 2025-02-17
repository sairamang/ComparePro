#include "Comparator.h"
#include <fstream>
#include <iostream>
bool Comparator::compare(CompareFile file1, CompareFile file2) {
    std::ifstream myFileHandle1;
    std::ifstream myFileHandle2;

    myFileHandle1.open(file1.getFilePath(), std::ios::in);
    myFileHandle2.open(file2.getFilePath(), std::ios::in);
    
    bool is_equal = true;

    if (myFileHandle1.is_open() && myFileHandle2.is_open()) {
        while((!myFileHandle1.eof()) && (!myFileHandle2.eof())) {
            char ch1;
            myFileHandle1.get(ch1);
            
            char ch2;
            myFileHandle2.get(ch2);
            
            if (ch1 != ch2) {
                is_equal = false;
                break;
            }
        }
    }
    if (myFileHandle1.eof() && (!myFileHandle2.eof())) {
        is_equal = false;
    }
    if ((!myFileHandle1.eof()) && myFileHandle2.eof()) {
        is_equal = false;
    }
    std::cout<<"Comparing "<<file1.getFilePath()<<" "<<file2.getFilePath()<<" "<<is_equal<<std::endl;
    return is_equal;
}