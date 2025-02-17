cmake_minimum_required(VERSION 3.20.0)
project(ComparePro)

include_directories(
    src/Utils
    src/FileHandler 
    src/Comparator
    src/CompareFile
    src/Common
    src/
)
add_subdirectory(test/googletest)
SET(CompareProSources 
src/Utils/Utils.cpp 
src/FileHandler/FileHandler.cpp 
src/CompareFile/CompareFile.cpp 
src/Comparator/Comparator.cpp
)
add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    ${CompareProSources}
)
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})
SET(TestSources
test/src/TestMain.cpp
test/src/TestUtils.cpp
test/src/TestCompareFile.cpp
test/src/TestFileHandler.cpp
)
add_test(NAME TestExecutable COMMAND TestExecutable)
enable_testing()

add_library(${PROJECT_NAME}_lib STATIC ${CompareProSources})
add_executable(TestExecutable ${TestSources})
target_link_libraries(TestExecutable ${PROJECT_NAME}_lib ${CMAKE_DL_LIBS} gtest_main)