#include "Obstacle.h"
#include <random>
#include "Snake.h"

Obstacle::Obstacle()
{
	pos_x = 100;
	pos_y = 100;
}

int Obstacle::randomPosition()
{
	srand(time(NULL));
	r_x =	tab_x[rand() % 15];
	r_y = tab_y[rand() % 14];
	std::cout << "tab[x} => " << pos_x << std::endl;
	std::cout << "tab[y] =>" << pos_y << std::endl;
	return r_x, r_y;
}

void Obstacle::drawObj(sf::RenderWindow& window)
{
	obstacle.setPosition(pos_x, pos_y);
	obstacle.setFillColor(sf::Color::White);
	obstacle.setSize(sf::Vector2f(50,50));
	window.draw(obstacle);
}
