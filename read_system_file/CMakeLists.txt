cmake_minimum_required(VERSION 3.5)

project(read_system_file)

add_definitions("-std=c++11")

add_executable(${PROJECT_NAME} read_system_file.cpp)
target_link_libraries(${PROJECT_NAME} PocoUtil PocoFoundation)


