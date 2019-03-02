cflags=`pkg-config --cflags --libs opencv` -o

build:
	#clang++ src/edges/edges.cpp `pkg-config --cflags --libs opencv` -o bin/edges
	#clang++ src/main.cpp `pkg-config --cflags --libs opencv` -o bin/main
	#clang++ src/tutorial.cpp `pkg-config --cflags --libs opencv` -o bin/tutorial
	clang++ src/faceputter.cpp ${cflags} bin/faceputter
	
run:
	./bin/faceputter
