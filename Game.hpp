#ifndef GAME_H
#define GAME_H
#define DEEP 10
#define WIDTH 25
#define DIM 8

#include <SFML/Graphics/RenderWindow.hpp>
#include "Cube.hpp"

class Game {
	public:
		Game();
    	void run();

	private: 
		void handleEvents();
		Cube a[DIM][DIM][DIM];
		void drawCube(int x, int y,sf::Color color);
		void drawContainer();
		sf::RenderWindow *window;
};


#endif
