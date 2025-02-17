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