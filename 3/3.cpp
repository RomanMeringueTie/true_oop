#include <iostream>
#include <ctime>
#include "3.hpp"

tPoint::tPoint() : x(getrand(1, WIDTH - 10)), y(getrand(1, HEIGHT - 10)), colour(getrand(0, 7)), direction(getrand(0, 7))
{
}

tPoint::tPoint(int x, int y, int colour, int direction) : x(x % (WIDTH - 10)), y(y % (HEIGHT - 10)), colour(colour % 7), direction(direction % 7)
{
}

tPoint::~tPoint()
{
}

float tPoint::get_x()
{
    return (float)x;
}
float tPoint::get_y()
{
    return (float)y;
}
sf::Color tPoint::get_colour()
{
    sf::Color colours[] = {sf::Color::White, sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan};
    return colours[colour];
};
void tPoint::line_move(int speed = 1)
{
    if (direction == right && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
    }
    else if (direction == right)
    {
        direction = left;
        x -= speed;
    }
    if (direction == left && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
    }
    else if (direction == left)
    {
        direction = right;
        x += speed;
    }
    if (direction == up && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        y -= speed;
    }
    else if (direction == up)
    {
        direction = down;
        y += speed;
    }
    if (direction == down && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        y += speed;
    }
    else if (direction == down)
    {
        direction = up;
        y -= speed;
    }
    if (direction == rightup && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
        y -= speed;
    }
    else if (direction == rightup)
    {
        direction = leftdown;
        x -= speed;
        y += speed;
    }
    if (direction == rightdown && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
        y += speed;
    }
    else if (direction == rightdown)
    {
        direction = leftup;
        x -= speed;
        y -= speed;
    }
    if (direction == leftup && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
        y -= speed;
    }
    else if (direction == leftup)
    {
        direction = rightdown;
        x += speed;
        y += speed;
    }
    if (direction == leftdown && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
        y += speed;
    }
    else if (direction == leftdown)
    {
        direction = rightup;
        x += speed;
        y -= speed;
    }
}
void tPoint::rand_move(int speed = 1)
{
    if (direction == right && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
    }
    if (direction == left && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
    }
    if (direction == up && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        y -= speed;
    }
    if (direction == down && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        y += speed;
    }
    if (direction == rightup && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
        y -= speed;
    }
    if (direction == rightdown && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x += speed;
        y += speed;
    }
    if (direction == leftup && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
        y -= speed;
    }
    if (direction == leftdown && x > 0 && x < WIDTH - 10 && y > 0 && y < HEIGHT - 10)
    {
        x -= speed;
        y += speed;
    }
    while (x <= 0 || x >= WIDTH - 10 || y <= 0 || y >= HEIGHT - 10)
    {
        int i = x;
        int j = y;
        direction = getrand(0, 7);
        if (direction == right)
        {
            i += speed;
        }
        if (direction == left)
        {
            i -= speed;
        }
        if (direction == up)
        {
            j -= speed;
        }
        if (direction == down)
        {
            j += speed;
        }
        if (direction == rightup)
        {
            i += speed;
            j -= speed;
        }
        if (direction == rightdown)
        {
            i += speed;
            j += speed;
        }
        if (direction == leftup)
        {
            i -= speed;
            j -= speed;
        }
        if (direction == leftdown)
        {
            i -= speed;
            j += speed;
        }
        if (!(i <= 0 || i >= WIDTH - 10 || j <= 0 || j >= HEIGHT - 10))
        {
            x = i;
            y = j;
        }
    }
}

int main()
{
    srand(time(NULL));
    tPoint array[100];
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "3 lab", sf::Style::Fullscreen);
    for (int i = 0; i < 100; i++)
    {
        sf::CircleShape shape(10);
        shape.setFillColor((array[i]).get_colour());
        shape.setPosition((array[i]).get_x(), (array[i]).get_y());
        window.draw(shape);
    }
    window.display();
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
                window.close();
        }
        for (int i = 0; i < 100; i++)
        {
            sf::CircleShape shape(10);
            shape.setFillColor((array[i]).get_colour());
            // array[i].line_move();
            array[i].rand_move();
            shape.setPosition((array[i]).get_x(), (array[i]).get_y());
            window.draw(shape);
        }
        window.display();
    }
    return 0;
}
