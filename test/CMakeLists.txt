cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(DataStructure)
add_subdirectory(DP)
add_subdirectory(Graph)
# add_subdirectory(Mathmatic)
# add_subdirectory(Other)
# add_subdirectory(Search)
add_subdirectory(String)
