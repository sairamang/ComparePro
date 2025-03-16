cmake_minimum_required(VERSION 3.20.0)
project(ComparePro)

#Dependency Checker
include(CMakePackageConfigHelpers)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gl_lib REQUIRED gl)
pkg_check_modules(glfw_lib REQUIRED glfw3)
SET(EXTERNAL_LIBS ${OPENGL_LIBS} ${glfw_lib_LINK_LIBRARIES} ${gl_lib_LINK_LIBRARIES})

# Include Directories for Compare Pro
include_directories(
    src/Utils
    src/FileHandler 
    src/Comparator
    src/CompareFile
    src/common
    src/FileDisplay
    src/
    imgui/
)

#IMGUI Gui Framework Added
SET(ImGUISources
    imgui/imgui.cpp 
    imgui/imgui_widgets.cpp 
    imgui/imgui_demo.cpp 
    imgui/imgui_draw.cpp 
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_glfw.cpp 
    imgui/backends/imgui_impl_opengl3.cpp  
)

#ComparePro Sources Added
SET(CompareProSources 
src/Utils/Utils.cpp 
src/FileHandler/FileHandler.cpp 
src/CompareFile/CompareFile.cpp 
src/Comparator/Comparator.cpp
src/FileDisplay/FileDisplay.cpp
src/FileDisplay/LoadFileWindow/LoadFileWindow.cpp
)

#Build Stage
add_executable( ${PROJECT_NAME} src/main.cpp ${CompareProSources} ${ImGUISources})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${EXTERNAL_LIBS})

set(TEST 1)
if (TEST) 
#Build Project as Static Lib for testing
add_library(${PROJECT_NAME}_lib STATIC ${CompareProSources} ${ImGUISources})

message("GTest Framework Added. Tests will be built")
add_subdirectory(test/googletest)

#TEST Sources Added
SET(TestSources
test/src/TestMain.cpp
test/src/TestUtils.cpp
test/src/TestCompareFile.cpp
test/src/TestFileHandler.cpp
test/src/TestFileDisplay.cpp
test/src/TestLoadFileWindow.cpp
)
add_test(NAME TestExecutable COMMAND TestExecutable)
enable_testing()
add_executable(TestExecutable ${TestSources})
target_link_libraries(TestExecutable ${PROJECT_NAME}_lib ${CMAKE_DL_LIBS} gtest_main ${EXTERNAL_LIBS})
endif(TEST)
add_custom_target(RunUnitTest
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/TestExecutable)

