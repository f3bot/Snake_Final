#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Owoc.h"


class Obstacle
{
public:
	int pos_x, pos_y;
	int r_x, r_y;
	Obstacle();
	int randomPosition();
	void drawObj(sf::RenderWindow& window);
	sf::Clock clock;
private:
	int tab_x[15] = { 350, 400 ,450 ,500 ,550 ,600 ,650 ,700 ,750 ,800 ,850 ,900 ,950 ,1000 ,1050 };
	int tab_y[14] = { 50 ,100 ,150 ,200 ,250, 300 ,350 ,400 ,450 ,500 ,550 ,600 ,650 ,700 };
	sf::RectangleShape obstacle;
};

