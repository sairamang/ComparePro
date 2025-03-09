#include "FileDisplay.h"
#include "gtest/gtest.h"
/*
1. File Display Initialization
2. File Display Destroy
3. File Display appear
4. File Display Show content
5. File Display Close button action
6. File Display Open File Action
*/

TEST(TestFileDisplay, InitializeFileDisplay) {
    FileDisplay myFileDisplay({720, 640});
}

TEST(TestFileDisplay, StartFileDisplay) {
    FileDisplay myFileDisplay({720,640});
    myFileDisplay.start();
    int count = 0;
    while(count < 10) {
        sleep(1);
        count++;
    }
}