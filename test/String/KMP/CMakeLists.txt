cmake_minimum_required(VERSION 3.10)

add_executable(TestKMP test_KMP.cpp)

target_link_libraries(TestKMP PRIVATE GTest::GTest GTest::Main)

add_test(NAME KMP COMMAND TestKMP)
