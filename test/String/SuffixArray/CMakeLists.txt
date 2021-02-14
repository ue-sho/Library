cmake_minimum_required(VERSION 3.10)

add_executable(TestSuffixArray test_suffix_array.cpp)

target_link_libraries(TestSuffixArray PRIVATE GTest::GTest GTest::Main)

add_test(NAME SuffixArray COMMAND TestSuffixArray)
