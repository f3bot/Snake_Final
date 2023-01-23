#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
class Snake
{
public:
	struct ssnake {
		int pos_x;
		int pos_y;
	};
	Snake();
	~Snake();
	void drawObj(sf::RenderWindow& window);
	void moveObj();
	void borderCollision(int width, int height);
	void segmentCollision();
	void owocCollision(int x, int y);
	void switch_snake(sf::Event& ev);
	void addSnakeBit();
	bool isDead = false;
	int size = 50;
	std::list<ssnake> snake = { {700,600}, {750,600}, {800,600}, {850,600}, {900,600} };
private:
	const sf::Color snake_color = sf::Color::Color(70, 155, 200);
	int nScore = 0;
	int direction = 3;
};

