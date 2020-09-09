cmake_minimum_required(VERSION 3.10)

add_executable(TestRollingHash test_rolling_hash.cpp)

target_link_libraries(TestRollingHash PRIVATE GTest::GTest GTest::Main)

add_test(NAME RollingHash COMMAND TestRollingHash)
