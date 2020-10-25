cmake_minimum_required(VERSION 3.10)

add_executable(TestZalgorithm test_Z-algorithm.cpp)

target_link_libraries(TestZalgorithm PRIVATE GTest::GTest GTest::Main)

add_test(NAME Z-algorithm COMMAND TestZalgorithm)
