#include "Game.hpp"

Game::Game()
{
   sf::ContextSettings settings;
   settings.antialiasingLevel = 8;
   window = new sf::RenderWindow(sf::VideoMode(800, 600), "Juego",sf::Style::Default,settings);

   int k, i, j;
   int x = 150,y = 100;

	for(k=0;k<DIM;k++)
		for (i=0;i<DIM;i++)
			for(j=0;j<DIM;j++)
			{
				a[k][i][j].setColor(sf::Color::White);
				a[k][i][j].setExiste(1);
				a[k][i][j].setX(x+j*WIDTH-k*WIDTH/2);
				a[k][i][j].setY(y+i*WIDTH+k*DEEP);

			 }   
   a[DIM-1][0][0].setExiste(0);   
	
}

void Game::drawCube(int x, int y, sf::Color color)
{


   sf::ConvexShape Polygon2;
   sf::ConvexShape Rec;
   sf::Texture texture;
   texture.loadFromFile("metal.png");
   texture.setSmooth(true);

   Rec.setPointCount(8);
   Rec.setPoint(0,sf::Vector2f(x,y));
   Rec.setPoint(1,sf::Vector2f(x+WIDTH,y));
   Rec.setPoint(2,sf::Vector2f(x+WIDTH,y+WIDTH));
   Rec.setPoint(3,sf::Vector2f(x,y+WIDTH));
   Rec.setPoint(4,sf::Vector2f(x,y));
   Rec.setPoint(5,sf::Vector2f(x+WIDTH/2,y-DEEP));
   Rec.setPoint(6,sf::Vector2f(x+WIDTH+WIDTH/2,y-DEEP));
   Rec.setPoint(7,sf::Vector2f(x+WIDTH,y));


   Rec.setOutlineThickness(1);
   Rec.setOutlineColor (sf::Color::Black);
   //Rec.setFillColor(color);
   Rec.setRotation(0);

   Rec.setTexture(&texture,false);


   Polygon2.setPointCount(4);
   Polygon2.setPoint(0,sf::Vector2f(x+WIDTH,y));
   Polygon2.setPoint(1,sf::Vector2f(x+WIDTH+WIDTH/2,y-DEEP));
   Polygon2.setPoint(2,sf::Vector2f(x+WIDTH+WIDTH/2,y+WIDTH-DEEP));
   Polygon2.setPoint(3,sf::Vector2f(x+WIDTH,y+WIDTH));
   Polygon2.setOutlineThickness(1);
   Polygon2.setOutlineColor (sf::Color::Black);
   //Polygon2.setFillColor(color);

   Polygon2.setRotation(0);
   Polygon2.setTexture(&texture,false);
   window->draw(Rec);
   window->draw(Polygon2);




}

void Game::drawContainer()
{
   for(int k = 0; k < DIM; k++)
      for(int i = DIM - 1; i >= 0; i--)
         for(int j = 0; j < DIM; j++)
         {
            if(a[k][i][j].getExiste() == 1)
               drawCube(a[k][i][j].getX(),a[k][i][j].getY(),a[k][i][j].getColor());
         }
}


void Game::run()
{
   while (window->isOpen())
   {
      sf::Event event;

      while (window->pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
         window->close();
      }

      window->clear();
      drawContainer();
      window->display();
   }
}