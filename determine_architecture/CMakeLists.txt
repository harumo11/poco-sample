cmake_minimum_required(VERSION 3.5)

project(determine_architecture)

add_executable(${PROJECT_NAME} determine_architecture.cpp)
target_link_libraries(${PROJECT_NAME} PocoFoundation)
