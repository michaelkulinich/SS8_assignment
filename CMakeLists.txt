cmake_minimum_required(VERSION 2.6)
project(mycd)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") 

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests myTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
