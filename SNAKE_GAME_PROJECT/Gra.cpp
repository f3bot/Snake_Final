#include "Gra.h"
#include "Snake.h"
#include "Owoc.h"
#include "HallOfFame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Obstacle.h"

Gra::Gra()
{
    Arial.loadFromFile("arial.ttf");
    ScoreSF.setFont(Arial);
    ScoreSF.setCharacterSize(36);
    ScoreSF.setFillColor(sf::Color::Red);
    TwojWynik.setFont(Arial);
    TwojWynik.setCharacterSize(36);
    TwojWynik.setFillColor(sf::Color::Red);
    Sekundy.setFont(Arial);
    Sekundy.setCharacterSize(36);
    Sekundy.setFillColor(sf::Color::Red);
    SekundyText.setFont(Arial);
    SekundyText.setCharacterSize(36);
    SekundyText.setFillColor(sf::Color::Red);
    ScoreSF.setPosition(sf::Vector2f(300, 0));
    Sekundy.setPosition(sf::Vector2f(-100, -100));
    SekundyText.setPosition(sf::Vector2f(-100, -100));
    SekundyText.setString("Dlugosc gry w sekundach =>");
    TwojWynik.setString("Twoj wynik to => ");
    hasStarted = false;
    condition = true;
}

Gra::~Gra()
{
    std::cout << "Gra usunieta\n";
}

void Gra::draw(sf::RenderWindow& window, HallOfFame ptr)
{
    Snake* snake = new Snake();
    Owoc* owoc = new Owoc();
    Obstacle* obs = new Obstacle();
    while (!snake->isDead)
    {

        sf::sleep(sf::Time(sf::milliseconds(100)));
        sf::Event event; //JK
        while (window.pollEvent(event))


            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                //RUSZANIE SIE SNAKIEM
                snake->switch_snake(event);
            }
        window.clear();

            if (owoc->owoc_utworzony == false) {
                owoc->randomPos();
            }

            if (owoc->owoc_utworzony == true) {
                owoc->drawObj(window);
            }

            if (snake->snake.front().pos_x == owoc->owoc_x && snake->snake.front().pos_y == owoc->owoc_y) {
                owoc->owoc_utworzony = false;
                snake->addSnakeBit();
                ptr.addScore();
            }

            if (snake->snake.front().pos_x == obs->pos_x && snake->snake.front().pos_y == obs->pos_y)
            {
                snake->isDead = true;
            }

            if (obs->clock.getElapsedTime().asSeconds() > 2.5)
            {
                obs->randomPosition();
                obs->pos_x = obs->r_x;
                obs->pos_y = obs->r_y;
                obs->clock.restart();
            }

            obs->drawObj(window);
            snake->drawObj(window);
            snake->moveObj();
            snake->snake.pop_back();
            snake->borderCollision(width, height);
            snake->segmentCollision();
            ptr.drawCurrentScore(window);
        window.display();
    }
    ptr.fStream();
}
