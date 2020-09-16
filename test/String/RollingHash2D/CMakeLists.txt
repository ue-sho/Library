cmake_minimum_required(VERSION 3.10)

add_executable(TestRollingHash2D test_rolling_hash_2D.cpp)

target_link_libraries(TestRollingHash2D PRIVATE GTest::GTest GTest::Main)

add_test(NAME RollingHash2D COMMAND TestRollingHash2D)
