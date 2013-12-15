cmake_minimum_required(VERSION 2.8)
project(aschWizrd)

find_package(qibuild)

set(_srcs
xml/pugiconfig.hpp
xml/pugixml.cpp
xml/pugixml.hpp)

# Create a executable named aschWizrd
# with the source file: main.cpp
qi_create_bin(aschWizrd "main.cpp" ${_srcs})

qi_use_lib(aschWizrd ALCOMMON)

# Add a simple test:
#enable_testing()
#qi_create_test(test_aschWizrd "test.cpp")
