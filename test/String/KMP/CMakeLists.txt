cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestKMP test_KMP.cpp)

target_link_libraries(TestKMP PRIVATE GTest::GTest GTest::Main)

include_directories(
    ${PROJECT_SOURCE_DIR}/algorithm/String
    ${GTEST_INCLUDE_DIRS}
    )

add_test(NAME KMP COMMAND TestKMP)
