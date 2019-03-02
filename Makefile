cflags=`pkg-config --cflags --libs opencv` -o

.edges:
	clang++ src/edges/edges.cpp ${cflags} bin/edges

.tutorial:
	clang++ src/tutorial.cpp ${cflags} bin/tutorial

.main:
	clang++ src/main.cpp ${cflags} bin/main

.faceputter:
	clang++ src/faceputter.cpp ${cflags} bin/faceputter

build: .edges .tutorial .main .faceputter

run faceputter:
	./bin/faceputter

install:

