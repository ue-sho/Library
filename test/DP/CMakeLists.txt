cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestDP test_dp.cpp)
target_link_libraries(TestDP GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/algorithm/DP ${GTEST_INCLUDE_DIRS})

# Google Testの各テストケースごとにCTestのテストを作成する
gtest_add_tests(TARGET TestDP)

# CTestのテストをひとつだけ作成する
# add_test(NAME AllTests COMMAND TestSample1)