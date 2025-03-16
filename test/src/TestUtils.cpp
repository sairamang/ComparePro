#include "Utils/Utils.h"
#include <gtest/gtest.h>
TEST(TestUtils, ValidFileTest) {
    EXPECT_EQ(Utils::isFileExists("../README.md"), true);
}
TEST(TestUtils, InValidFileTest) {
    EXPECT_EQ(Utils::isFileExists(""), false);
}
TEST(TestUtils, PrintUsage) {
    Utils::printUsage();
}

TEST(TestUtils, ListFilesInDirectory) {
    Utils::ListCurrentFilesinDirectory("./");
}

TEST(TestUtils, getCurrentWorkingDirectory) {
    std::cout<<"Get Current working dir"<<Utils::getCurrentWorkingDirectory()<<std::endl;
}
TEST(TestUtils, sanitizeCurrWorkingDirectory) {
    EXPECT_EQ("/",Utils::sanitizeCurrWorkingDirectory("/root/repo/../../"));
    EXPECT_EQ("/root/",Utils::sanitizeCurrWorkingDirectory("/root/repo/../"));
}