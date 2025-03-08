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
    FileDisplay myfileDisplay;
    EXPECT_NE(&myfileDisplay, nullptr);
}

TEST(TestFileDisplay, DestroyFileDisplay) {
    FileDisplay* myFileDisplay_handle = new FileDisplay();
    
}