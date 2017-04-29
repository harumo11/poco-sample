cmake_minimum_required(VERSION 3.5)

project(process_launch)

add_definitions("-std=c++11")

add_executable(${PROJECT_NAME} process_launch.cpp)
target_link_libraries(${PROJECT_NAME} PocoUtil PocoFoundation)


