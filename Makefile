build:
	clang++ ./src/main.cpp `pkg-config --libs opencv` -o main
	clang++ ./src/dylan.cpp `pkg-congfig --libs opencv` -o dylan
