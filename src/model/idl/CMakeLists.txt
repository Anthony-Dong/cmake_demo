project(lib_idl)

add_library(${PROJECT_NAME} SHARED model.pb.cc common.pb.cc utils.cpp)

## link protobuf
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/include)
target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/lib)
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf)
