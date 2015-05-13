#Makefile
game:		main.o Cube.o Game.o
		g++ main.o Cube.o Game.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o:		main.cpp
		g++ -c main.cpp

Cube.o:		Cube.cpp Cube.hpp
		g++ -c Cube.cpp

Game.o:		Game.cpp Game.hpp
		g++ -c Game.cpp