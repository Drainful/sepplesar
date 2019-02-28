run:
	./bin/main

build:
<<<<<<< HEAD
	clang++ ./src/main.cpp `pkg-config --libs opencv` -o main
	clang++ ./src/dylan.cpp `pkg-congfig --libs opencv` -o dylan
=======
	clang++ src/main.cpp `pkg-config --libs opencv` -o main
>>>>>>> 1c08b11699a1803efa360788c366e01bd9379cc2
