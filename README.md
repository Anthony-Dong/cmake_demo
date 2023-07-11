# CMake Demo

## 环境

- C++11 

```shell
~ gcc --version
gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

~ cmake --version
cmake version 3.7.2

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## 运行此项目

```shell
~/go/src/github.com/anthony-dong/cmake_demo make run
output/cmake_demo
hello world!
id_: 1 name_: 1314班 c_time_: 0
people: {"ID":"1","Name":"tom"}
out {"ID":"1","Name":"tom"}!
Welcome to The Village, Number 6!
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

3. 本项目采用 git submodule 模式，对于依赖属于静态代码依赖(也是比较推荐的模式)，方便学习和调试代码