cmake_minimum_required(VERSION 3.8.0)

project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src/model/db)
add_subdirectory(src/model/idl)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/include src/model)

target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/lib)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt db_model lib_idl)