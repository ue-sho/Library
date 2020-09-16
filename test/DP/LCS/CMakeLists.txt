cmake_minimum_required(VERSION 3.10)

add_executable(TestLCS test_lcs.cpp)

target_link_libraries(TestLCS PRIVATE GTest::GTest GTest::Main)

add_test(NAME LCS COMMAND TestLCS)
