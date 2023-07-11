.PHONY: all clean build run

all: build

clean:
	@rm -rf output

build: ## if cmake > 3.8.0 ;  -DABSL_PROPAGATE_CXX_STD:BOOL=ON
	@if [ ! -d output ]; then \
  		mkdir -p output && \
  		cd output && \
  		cmake -G "Unix Makefiles" -Dprotobuf_BUILD_TESTS:BOOL=OFF -DBUILD_TESTING:BOOL=OFF ../;  \
  	fi
	@cmake --build output

run: build
	output/cmake_demo