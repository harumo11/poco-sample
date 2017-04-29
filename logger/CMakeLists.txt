cmake_minimum_required(VERSION 3.5)

project(logger)

add_executable(${PROJECT_NAME} logger.cpp)

target_link_libraries(${PROJECT_NAME} PocoFoundation)
