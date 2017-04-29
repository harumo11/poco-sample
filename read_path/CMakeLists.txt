cmake_minimum_required(VERSION 3.5)

project(read_path)

add_executable(${PROJECT_NAME} read_path.cpp)

target_link_libraries(${PROJECT_NAME} PocoFoundation)
