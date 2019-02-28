run:
	./bin/main

build:
	clang++ ./src/main.cpp `pkg-config --libs opencv` -o main
