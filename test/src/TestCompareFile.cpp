#include "CompareFile.h"
#include <gtest/gtest.h>
#include <memory>
class CompareFileCreation : public testing::Test {
protected:
    CompareFileCreation() {
        myFile = std::make_shared<CompareFile>("../README.md");
    }
    ~CompareFileCreation() {

    }
    std::shared_ptr<CompareFile> myFile;
};

TEST_F(CompareFileCreation, CompareFile) {
    EXPECT_EQ(myFile->getFilePath(), "../README.md");
}
