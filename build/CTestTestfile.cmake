# CMake generated Testfile for 
# Source directory: /root/repo/ComparePro
# Build directory: /root/repo/ComparePro/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[TestExecutable]=] "/root/repo/ComparePro/build/TestExecutable")
set_tests_properties([=[TestExecutable]=] PROPERTIES  _BACKTRACE_TRIPLES "/root/repo/ComparePro/CMakeLists.txt;31;add_test;/root/repo/ComparePro/CMakeLists.txt;0;")
subdirs("test/googletest")
