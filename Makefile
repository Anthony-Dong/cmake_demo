.PHONY: all clean build run

all: run

clean:
	@rm -rf output

build: clean
	@mkdir -p output && cd output && \
	cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../ && \
	make

run: build
	cd output && ./cmake_demo