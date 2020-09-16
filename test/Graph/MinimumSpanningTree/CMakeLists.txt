cmake_minimum_required(VERSION 3.10)

add_executable(TestMST_kruskal test_MST_kruskal.cpp)
add_executable(TestMST_prim test_MST_prim.cpp)

target_link_libraries(TestMST_kruskal PRIVATE GTest::GTest GTest::Main)
target_link_libraries(TestMST_prim PRIVATE GTest::GTest GTest::Main)

add_test(NAME MST_kruskal COMMAND TestMST_kruskal)
add_test(NAME MST_prim COMMAND TestMST_prim)
