cflags=`pkg-config --cflags --libs opencv` -o

build-edges:
	clang++ src/edges/edges.cpp `pkg-config --cflags --libs opencv` -o bin/edges

build-tutorial:
	clang++ src/tutorial.cpp `pkg-config --cflags --libs opencv` -o bin/tutorial

build-main:
	clang++ src/main.cpp `pkg-config --cflags --libs opencv` -o bin/main

build-faceputter:
	clang++ src/faceputter.cpp ${cflags} bin/faceputter

build: build-edges build-tutorial build-main build-faceputter

run:
	./bin/faceputter
