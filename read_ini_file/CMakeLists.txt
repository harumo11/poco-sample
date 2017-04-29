cmake_minimum_required(VERSION 3.5)

project(read_ini_file)

#add_definitions("-std=c++11")は必須．どうやら，pocoはc++11が標準らしい
add_definitions("-std=c++11")

add_executable(${PROJECT_NAME} read_ini_file.cpp)
target_link_libraries(${PROJECT_NAME} PocoFoundation PocoUtil)
