#include <gtest/gtest.h>
#include <FileHandler/FileHandler.h>
TEST(TestFileHandler,FileHandlerCreation) {
    FileHandler myFileHandler;
    EXPECT_NE(nullptr, &myFileHandler);
}
TEST(TestFileHandler, AddFileToCompare) {
    FileHandler myFileHandler;
    CompareFile myFile("/root/repo/ComparePro/README.md");
    myFileHandler.addFileToCompare(myFile);
    std::vector<CompareFile> myFiles;
    myFileHandler.getListOfFiles(myFiles);
    EXPECT_NE(myFiles.empty(), true);
    bool found = false;
    for(auto it : myFiles) {
        if (it.getFilePath() == "/root/repo/ComparePro/README.md") {
            found = true;
        }
    }
    EXPECT_EQ(found , true);
}
TEST(TestFileHandler, RemoveFileToCompare) {
    FileHandler myFileHandler;
    CompareFile myFile("/root/repo/ComparePro/README.md");
    myFileHandler.addFileToCompare(myFile);
    myFileHandler.removeFileFromCompare(myFile);
    std::vector<CompareFile> myFiles;
    myFileHandler.getListOfFiles(myFiles);
    EXPECT_EQ(myFiles.empty(), true);
    bool found = false;
    for(auto it : myFiles) {
        if (it.getFilePath() == "/root/repo/ComparePro/README.md") {
            found = true;
        }
    }
    EXPECT_EQ(found , false);
}
TEST(TestFileHandler, CompareListOfFilesDifferent) {
    FileHandler myFileHandler;
    CompareFile myFile1("../README.md");
    CompareFile myFile2("../README.md");
    myFileHandler.addFileToCompare(myFile1);
    myFileHandler.addFileToCompare(myFile2);
    std::vector<CompareFile> myFiles;
    myFileHandler.getListOfFiles(myFiles);
    myFileHandler.compareListOfFiles();
}

TEST(TestFileHandler, CompareListOfFilesSame) {
    FileHandler myFileHandler;
    CompareFile myFile1("../README.md");
    CompareFile myFile2("../CMakeLists.txt");
    myFileHandler.addFileToCompare(myFile1);
    myFileHandler.addFileToCompare(myFile2);
    std::vector<CompareFile> myFiles;
    myFileHandler.getListOfFiles(myFiles);
    myFileHandler.compareListOfFiles();
}