cmake_minimum_required(VERSION 3.5)

project(read_environment)

add_executable(${PROJECT_NAME} read_environment.cpp)
target_link_libraries(${PROJECT_NAME} PocoFoundation)
