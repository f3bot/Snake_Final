#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Snake.h"
class Owoc :public Snake
{

public:
	int owoc_x, owoc_y;
	Owoc();
	void drawObj(sf::RenderWindow& window);
	int randomPos();
	bool owocZjedzony;
	bool owoc_utworzony;
	void owocCollision();
private:
	int tab_x[15] = { 350, 400 ,450 ,500 ,550 ,600 ,650 ,700 ,750 ,800 ,850 ,900 ,950 ,1000 ,1050 };
	int tab_y[14] = { 50 ,100 ,150 ,200 ,250, 300 ,350 ,400 ,450 ,500 ,550 ,600 ,650 ,700 };
	int losowy_x;
	int losowy_y;
	int rand_x, rand_y;
	sf::RectangleShape part;
};

