#pragma once
#include <string>
class CompareFile {
    public:
        CompareFile() = delete;
        CompareFile(std::string filepath);
        int32_t getFileId();
        std::string getFilePath();
    private:
        std::string m_filePath;
        static int32_t file_count;
        int32_t m_fileid;
};