cmake_minimum_required(VERSION 3.10)

add_executable(TestDjkstra test_djkstra.cpp)

target_link_libraries(TestDjkstra PRIVATE GTest::GTest GTest::Main)

add_test(NAME Dijkstra COMMAND TestDjkstra)
