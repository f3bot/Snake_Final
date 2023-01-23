#include "Snake.h"
#include "Owoc.h"

Snake::Snake()
{
    std::cout << "snake utworzony " << std::endl;
}

Snake::~Snake()
{
    std::cout << "snake usuniety" << std::endl;
}

void Snake::drawObj(sf::RenderWindow& window)
{
    for (auto s : snake) {
        sf::RectangleShape part;
        part.setPosition(s.pos_x, s.pos_y);
        part.setSize(sf::Vector2f(size, size));
        part.setFillColor(snake_color);
        window.draw(part);
    }
}

void Snake::moveObj()
{
    switch (direction) {
    case 0: //gora
        snake.push_front({ snake.front().pos_x, snake.front().pos_y - size });
        break;
    case 1: //prawo
        snake.push_front({ snake.front().pos_x + size, snake.front().pos_y });
        break;
    case 2: //dol
        snake.push_front({ snake.front().pos_x, snake.front().pos_y + size });
        break;
    case 3: //lewo
        snake.push_front({ snake.front().pos_x - size, snake.front().pos_y });
        break;
    }
}

void Snake::borderCollision(int width, int height)
{
    if (snake.front().pos_x < 0 || snake.front().pos_x > height)
        isDead = true;
    if (snake.front().pos_y < 0 || snake.front().pos_y > width)
        isDead = true;

}

void Snake::segmentCollision()
{
    for (std::list<ssnake>::iterator i = snake.begin(); i != snake.end(); i++)
    {
        if (i != snake.begin() && i->pos_x == snake.front().pos_x && i->pos_y == snake.front().pos_y)
            isDead = true;
    }
}

void Snake::switch_snake(sf::Event& ev)
{
    switch (ev.key.code) {
    case::sf::Keyboard::Up:
        direction = 0;
        break;
    case::sf::Keyboard::Down:
        direction = 2;
        break;
    case::sf::Keyboard::Right:
        direction = 1;
        break;
    case::sf::Keyboard::Left:
        direction = 3;
        break;
    }
}

void Snake::addSnakeBit()
{
    snake.push_back({ snake.back().pos_x, snake.back().pos_y });
}

