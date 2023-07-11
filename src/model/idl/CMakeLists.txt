project(lib_model_idl)

add_library(${PROJECT_NAME} ${module_is_static} model.pb.h model.pb.cc common.pb.h common.pb.cc utils.h utils.cpp)

message("protoc_LIBRARIES" "${protoc_LIBRARIES}")

target_link_libraries(${PROJECT_NAME} PUBLIC ${protoc_LIBRARIES})
