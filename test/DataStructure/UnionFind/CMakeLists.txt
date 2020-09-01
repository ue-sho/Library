cmake_minimum_required(VERSION 3.10)

add_executable(TestUnionFind test_union_find.cpp)

target_link_libraries(TestUnionFind PRIVATE GTest::GTest GTest::Main)

add_test(NAME UnionFind COMMAND TestUnionFind)
