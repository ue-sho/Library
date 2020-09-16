cmake_minimum_required(VERSION 3.10)

add_executable(TestWarshalFroyd test_warshal_froyd.cpp)

target_link_libraries(TestWarshalFroyd PRIVATE GTest::GTest GTest::Main)

add_test(NAME WarshalFroyd COMMAND TestWarshalFroyd)
