cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/algorithm/String
                    ${GTEST_INCLUDE_DIRS})

add_subdirectory(KMP)
