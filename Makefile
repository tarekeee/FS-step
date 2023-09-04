output: main.o
	g++ main.o -o output -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp drawer.hpp graph.hpp drawers.hpp
	g++ -c main.cpp