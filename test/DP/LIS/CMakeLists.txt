cmake_minimum_required(VERSION 3.10)

add_executable(TestLIS test_lis.cpp)

target_link_libraries(TestLIS PRIVATE GTest::GTest GTest::Main)

add_test(NAME LIS COMMAND TestLIS)
