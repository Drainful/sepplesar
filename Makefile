build:
	clang++ src/dylan.cpp `pkg-config --cflags --libs opencv` -o dylan
	clang++ src/main.cpp `pkg-config --cflags --libs opencv` -o main

run:
	./bin/dylan src/test.jpg 
