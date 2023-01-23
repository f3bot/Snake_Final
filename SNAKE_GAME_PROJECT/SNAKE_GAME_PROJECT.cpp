#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Owoc.h"
#include "Gra.h"
#include "HallOfFame.h"
#include  <algorithm>

int main()
{
    Gra* gra = new Gra();
    HallOfFame hof;
    sf::RenderWindow window(sf::VideoMode(1120, 760), "Snake!");

    hof.inputUsername(window);

    gra->draw(window, hof);

    hof.readFromFile();

    hof.draw(window);

    return 0;
}