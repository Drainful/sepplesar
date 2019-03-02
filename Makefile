build:
	clang++ src/edges.cpp `pkg-config --cflags --libs opencv` -o edges
	#clang++ src/main.cpp `pkg-config --cflags --libs opencv` -o main
	clang++ src/tutorial.cpp `pkg-config --cflags --libs opencv` -o tutorial

run:
	./edges src/test.png
