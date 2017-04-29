cmake_minimum_required(VERSION 3.5)

project(make_directories)

add_executable(${PROJECT_NAME} make_directories.cpp)

target_link_libraries(${PROJECT_NAME} PocoFoundation)
