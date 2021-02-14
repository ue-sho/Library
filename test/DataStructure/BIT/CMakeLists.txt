cmake_minimum_required(VERSION 3.10)

add_executable(TestBIT test_BIT.cpp)

target_link_libraries(TestBIT PRIVATE GTest::GTest GTest::Main)

add_test(NAME BIT COMMAND TestBIT)
