#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "HallOfFame.h"

class Gra
{
public:
	Gra();
	~Gra();
	void draw(sf::RenderWindow& window, HallOfFame ptr);
	void gameEnd(sf::RenderWindow& window);
	void currentScore(sf::RenderWindow& window);
	void addScore();
	void fstream();
	const int height = 1080;
	const int width = 720;
	bool hasStarted;
	bool condition;
private:
	sf::Font Arial;
	sf::Text ScoreSF;
	sf::Text TwojWynik;
	sf::Text Sekundy;
	sf::Text SekundyText;
};

