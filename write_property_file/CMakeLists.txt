cmake_minimum_required(VERSION 3.5)

project(write_property_file)

add_definitions("-std=c++11")

add_executable(${PROJECT_NAME} write_property_file.cpp)

target_link_libraries(${PROJECT_NAME} PocoFoundation PocoUtil)
