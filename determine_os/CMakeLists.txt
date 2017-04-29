cmake_minimum_required(VERSION 3.5)

project(determine_os)

add_executable(${PROJECT_NAME} determine_os.cpp)
target_link_libraries(${PROJECT_NAME} PocoFoundation)
