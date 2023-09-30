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

class tFigure
{
protected:
    int x;
    int y;
    int colour;
    int direction;
    int height;
    int width;
    float angle;

public:
    tFigure();
    tFigure(int x, int y, int colour, int direction);
    ~tFigure();
    float get_x();
    float get_y();
    sf::Color get_colour();
    void virtual line_move(int speed);
    void virtual rand_move(int speed);
    void virtual draw(sf::RenderWindow &window);
    void rotate();
};

class tPoint: public tFigure
{
    public:
    tPoint();
    tPoint(int x, int y, int colour, int direction);
    ~tPoint();
    void draw(sf::RenderWindow &window);
};

class tLine: public tFigure
{
    public:
    tLine();
    tLine(int x, int y, int colour, int direction);
    ~tLine();
    void draw(sf::RenderWindow &window);
};

class tCircle: public tFigure
{
    public:
    tCircle();
    tCircle(int x, int y, int colour, int direction);
    ~tCircle();
    void draw(sf::RenderWindow &window);
};

class tRectangle: public tFigure
{
    public:
    tRectangle();
    tRectangle(int x, int y, int colour, int direction);
    ~tRectangle();
    void draw(sf::RenderWindow &window);
};

class tTriangle: public tFigure
{
    public:
    tTriangle();
    tTriangle(int x, int y, int colour, int direction);
    ~tTriangle();
    void draw(sf::RenderWindow &window);
};

class tEllipse: public tFigure
{
    public:
    tEllipse();
    tEllipse(int x, int y, int colour, int direction);
    ~tEllipse();
    void draw(sf::RenderWindow &window);
};

class tRhombus: public tFigure
{
    public:
    tRhombus();
    tRhombus(int x, int y, int colour, int direction);
    ~tRhombus();
    void draw(sf::RenderWindow &window);
};