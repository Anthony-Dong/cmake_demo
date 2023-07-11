# CMake Demo

## 前置准备

> 感受下编译的时间都可以自己吃完泡面，其他语言你都体验不到！个人建议编译release版本，而非master分支!

1. 下载 protoc: https://github.com/protocolbuffers/protobuf

```shell
# 1. 下载protoc
wget https://github.com/protocolbuffers/protobuf/archive/refs/tags/v3.19.0.tar.gz -O- | tar -zxvf -

cd protobuf-3.19.0

# 2. 进入release目录
cd cmake && mkdir -p release && cd release

# 3. 构建cmake
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -Dprotobuf_BUILD_SHARED_LIBS=ON -Dprotobuf_BUILD_PROTOC_BINARIES=ON  -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local  ../.

# 4. 安装
make install
```

2. 下载fmt: https://github.com/fmtlib/fmt

```shell
wget https://github.com/fmtlib/fmt/archive/refs/tags/9.1.0.tar.gz -O- | tar -zxvf -
cd fmt-9.1.0
cmake -DBUILD_SHARED_LIBS=TRUE .
make install
```

3. 下载 abseil

你可以理解这个库主要是解决C++11(低版本)预览一些C++14/其他高版本的一些高级特性库

```shell
#  https://github.com/abseil/abseil-cpp/releases/tag/20220623.1 是abseil最后一个支持C++11的版本
wget https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz -O - | tar -zxvf -

cd abseil-cpp-20220623.1

cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DABSL_ENABLE_INSTALL=ON -DABSL_USE_EXTERNAL_GOOGLETEST=ON -DABSL_FIND_GOOGLETEST=ON -DCMAKE_CXX_STANDARD=11 ..
```

- 如何引入absl,这里就需要了解cmake的find_package机制，具体可以看文章: https://zhuanlan.zhihu.com/p/97369704

```cmake
find_package(absl CONFIG REQUIRED)
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
target_link_libraries(${PROJECT_NAME} PUBLIC ${absl_LIBRARIES})
```

## 运行此项目

```shell
make run
```

## 使用

```text
➜  cmake_demo git:(master) ✗ make 
-- The C compiler identification is AppleClang 13.0.0.13000027
-- The CXX compiler identification is AppleClang 13.0.0.13000027
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMAKE_VERSION:3.25.1
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/bytedance/go/src/github.com/anthony-dong/cmake_demo/output
[ 12%] Building CXX object src/model/idl/CMakeFiles/lib_idl.dir/model.pb.cc.o
[ 25%] Building CXX object src/model/idl/CMakeFiles/lib_idl.dir/common.pb.cc.o
[ 37%] Building CXX object src/model/idl/CMakeFiles/lib_idl.dir/utils.cpp.o
[ 50%] Linking CXX shared library liblib_idl.dylib
[ 50%] Built target lib_idl
[ 62%] Building CXX object src/model/db/CMakeFiles/db_model.dir/Class.cpp.o
[ 75%] Linking CXX shared library libdb_model.dylib
[ 75%] Built target db_model
[ 87%] Building CXX object CMakeFiles/cmake_demo.dir/main.cpp.o
[100%] Linking CXX executable cmake_demo
[100%] Built target cmake_demo
cd output && ./cmake_demo
hello world!
hello world!
id: 1, name: 1314班
people: {"ID":"1","Name":"tom"}
people: {"ID":"1","Name":"tom"}
```

## 注意

1. 如果出现了下面这个报错，执行 `sudo ldconfig` 即可.

```text
./cmake_demo: error while loading shared libraries: libfmt.so.9: cannot open shared object file: No such file or directory
```

2. 高版本的Cmake可以使用以下命令直接构建

```shell
mkdir -p output
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -S . -B output
cd output
make
```