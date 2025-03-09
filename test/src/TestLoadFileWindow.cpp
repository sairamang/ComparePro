#include "LoadFileWindow/LoadFileWindow.h"
#include "FileDisplay/FileDisplay.h"
#include "gtest/gtest.h"
TEST(LoadFileWindow, Initialize) {
    LoadFileWindow mywindow;
    FileDisplay myFileDisplay({720,640});
    myFileDisplay.start();
}