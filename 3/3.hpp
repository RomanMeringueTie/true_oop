#pragma once
#include <SFML/Graphics.hpp>
#define HEIGHT 1080
#define WIDTH 1920

enum Colour
{
    White,
    Red,
    Green,
    Blue,
    Yellow,
    Magenta,
    Cyan
};

enum Direction
{
    right,
    left,
    up,
    down,
    rightup,
    rightdown,
    leftup,
    leftdown
};

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

class tPoint
{
protected:
    int x;
    int y;
    int colour;
    int direction;

public:
    tPoint();
    tPoint(int x, int y, int colour, int direction);
    ~tPoint();
    float get_x();
    float get_y();
    sf::Color get_colour();
    void line_move(int speed);
    void rand_move(int speed);
};
