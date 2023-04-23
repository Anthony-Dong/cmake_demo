.PHONY: all


all: build

build:
	if $$(protoc --version | grep -v '3.19.0') ; then echo "protoc version must is 3.19.0" ;  exit 1; fi
	protoc -I . --cpp_out=. common.proto model.proto