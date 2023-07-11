# 设置项目名称
project(lib_model_db)

set(DB_MODEL_SOURCES Class.cpp Class.h++)

message(module_is_static: "${module_is_static}")

## 设置target 为一个可执行文件
add_library(${PROJECT_NAME} ${module_is_static} ${DB_MODEL_SOURCES})
