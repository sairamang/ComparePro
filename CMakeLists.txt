cmake_minimum_required(VERSION 3.20.0)
project(ComparePro)

message("Finding Package OpenGL, glfw")
include(CMakePackageConfigHelpers)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gl_lib REQUIRED gl)
pkg_check_modules(glfw_lib REQUIRED glfw3)
include_directories(
    src/Utils
    src/FileHandler 
    src/Comparator
    src/CompareFile
    src/Common
    src/FileDisplay
    src/
    imgui/
)

SET(ImGUISources
    imgui/imgui.cpp 
    imgui/imgui_widgets.cpp 
    imgui/imgui_demo.cpp 
    imgui/imgui_draw.cpp 
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_glfw.cpp 
    imgui/backends/imgui_impl_opengl3.cpp  
) 
SET(CompareProSources 
src/Utils/Utils.cpp 
src/FileHandler/FileHandler.cpp 
src/CompareFile/CompareFile.cpp 
src/Comparator/Comparator.cpp
src/FileDisplay/FileDisplay.cpp
)
add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    ${CompareProSources}
    ${ImGUISources}
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${OPENGL_LIBS} ${glfw_lib_LINK_LIBRARIES} ${gl_lib_LINK_LIBRARIES})

if (TEST) 
message("Test Added")
add_subdirectory(test/googletest)
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
endif(TEST)