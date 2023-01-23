#include "Owoc.h"
#include "Snake.h"
#include <list>
#include <time.h>
#include <random>

Owoc::Owoc()
{
	owoc_x = 0;
	owoc_y = 0;
	owoc_utworzony = false;
	owocZjedzony = false;
	rand_x = 0;
	rand_y = 0;
	losowy_x = 0;
	losowy_y = 0;
	std::cout << "owoc utworzony" << std::endl;
}

void Owoc::drawObj(sf::RenderWindow& window)
{
	owoc_x = losowy_x;
	owoc_y = losowy_y;
	part.setPosition(owoc_x, owoc_y);
	part.setSize(sf::Vector2f(size, size));
	part.setFillColor(sf::Color::Red);
	window.draw(part);
}

int Owoc::randomPos()
{
	owoc_utworzony = true;
	srand(time(NULL));
	rand_x = rand() % 15;
	std::cout << "x => " << rand_x << std::endl;
	rand_y = rand() % 14;
	std::cout << "y => " << rand_y << std::endl;
	losowy_x = tab_x[rand_x];
	losowy_y = tab_y[rand_y];
	std::cout << "tab[x} => " << losowy_x << std::endl;
	std::cout << "tab[y] =>" << losowy_y << std::endl;
	return losowy_x, losowy_y;
}

void Owoc::owocCollision()
{
	if (snake.front().pos_x == owoc_x && snake.front().pos_y == owoc_y) {
		std::cout << "KLASA OWOC KOLIZJA" << std::endl;
		owoc_utworzony = false;
	}
}
