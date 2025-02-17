#include "CompareFile.h"
int32_t CompareFile::file_count = 0;
CompareFile::CompareFile(std::string filePath) : m_filePath(filePath) {
    m_fileid = file_count++;
}

int32_t CompareFile::getFileId() {
    return m_fileid;
}

std::string CompareFile::getFilePath() {
    return m_filePath;
}