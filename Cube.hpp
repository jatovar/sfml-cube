#ifndef CUBE_H
#define CUBE_H
#include <SFML/Graphics.hpp>

class Cube 	{

	public:
		Cube();
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		void setColor(const sf::Color& color);
		sf::Color getColor();
		void setExiste(int val);
		int getExiste();
	private:
		int x;
		int y;
		sf::Color color;	
		int existe;
};


#endif
