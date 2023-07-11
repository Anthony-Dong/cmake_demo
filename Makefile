.PHONY: all clean build run

all: build

clean:
	@rm -rf output

build:
	@if [ ! -d output ]; then \
  		mkdir -p output && \
  		cd output && \
  		cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -Dprotobuf_BUILD_TESTS:BOOL=OFF -DABSL_PROPAGATE_CXX_STD:BOOL=ON ../;  \
  	fi
	@cmake --build output

run: build
	output/cmake_demo