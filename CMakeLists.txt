cmake_minimum_required(VERSION 3.0.0)

project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

message(CMAKE_VERSION: ${CMAKE_VERSION})

add_subdirectory(src/model/db)
add_subdirectory(src/model/idl)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/include src/model)
if (${CMAKE_VERSION} VERSION_LESS 3.13)
    link_directories(/usr/local/lib)
else ()
    target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/lib)
endif ()
target_link_libraries(${PROJECT_NAME} PUBLIC fmt db_model lib_idl)