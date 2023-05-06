project(lib_idl)

add_library(${PROJECT_NAME} SHARED model.pb.cc common.pb.cc utils.cpp)

## link protobuf
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/include)

if (${CMAKE_VERSION} VERSION_LESS 3.13)
    link_directories(/usr/local/lib)
else ()
    target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/lib)
endif ()

target_link_libraries(${PROJECT_NAME} PUBLIC protobuf)
