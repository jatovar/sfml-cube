#include "Cube.hpp"

Cube::Cube()
{

}
int Cube::getX()
{
	return this->x;
}

int Cube::getY()
{
	return this->y;
}

void Cube::setX(int x)
{
	this->x = x;
}

void Cube::setY(int y)
{
	this->y = y;
}

void Cube::setColor(const sf::Color& color)
{
	this->color = color;
}

void Cube::setExiste(int val)
{
	this->existe = val;
}
int Cube::getExiste()
{
	return this->existe;
}
sf::Color Cube::getColor()
{
	return this->color;
}