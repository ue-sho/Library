cmake_minimum_required(VERSION 3.10)

add_executable(TestBellmanFord test_bellman_ford.cpp)

target_link_libraries(TestBellmanFord PRIVATE GTest::GTest GTest::Main)

add_test(NAME BellmanFord COMMAND TestBellmanFord)
