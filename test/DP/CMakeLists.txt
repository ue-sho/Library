cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestDP test_lcs.cpp test_lis.cpp)
target_link_libraries(TestDP GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/algorithm/DP ${GTEST_INCLUDE_DIRS})

gtest_add_tests(TARGET TestDP)
