# 设置项目名称
project(db_model)

set(DB_MODEL_SOURCES Class.cpp)

## 设置target 为一个可执行文件
add_library(${PROJECT_NAME} SHARED ${DB_MODEL_SOURCES})