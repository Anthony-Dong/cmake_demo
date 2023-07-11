cmake_minimum_required(VERSION 3.8.0)

project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-Winvalid-noreturn")

message(CMAKE_VERSION: ${CMAKE_VERSION})

set(module_is_static STATIC)

add_subdirectory(third_party)

set(absl_LIBRARIES
        absl::algorithm
        absl::base
        absl::debugging
        absl::btree
        absl::hash
        absl::memory
        absl::meta
        absl::numeric
        absl::status
        absl::str_format
        absl::strings
        absl::synchronization
        absl::time
        absl::utility)

set(fmt_LIBRARIES fmt::fmt)
set(protoc_LIBRARIES protobuf::libprotobuf)

add_subdirectory(src/model/db)
add_subdirectory(src/model/idl)

set(src_LIBRARIES lib_model_idl lib_model_db)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${fmt_LIBRARIES} ${absl_LIBRARIES} ${protoc_LIBRARIES} ${src_LIBRARIES})