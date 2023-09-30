#include <iostream>
#include <ctime>
#include <vector>
#include "6.hpp"

tFigure::tFigure() : x(getrand(400, WIDTH-400)), y(getrand(400, HEIGHT-400)), colour(getrand(0, 7)), direction(getrand(0, 7)), angle(0)
{
}

tFigure::tFigure(int x, int y, int colour, int direction) : x(x % (WIDTH - 400)), y(y % (HEIGHT - 400)), colour(colour % 7), direction(direction % 7)
{
}

tFigure::~tFigure()
{
}

float tFigure::get_x()
{
    return (float)x;
}
float tFigure::get_y()
{
    return (float)y;
}
sf::Color tFigure::get_colour()
{
    sf::Color colours[] = {sf::Color::White, sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan};
    return colours[colour];
};
void tFigure::line_move(int speed)
{
    if (direction == right && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x += speed;
    }
    else if (direction == right)
    {
        direction = left;
        x -= speed;
    }
    if (direction == left && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x -= speed;
    }
    else if (direction == left)
    {
        direction = right;
        x += speed;
    }
    if (direction == up && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        y -= speed;
    }
    else if (direction == up)
    {
        direction = down;
        y += speed;
    }
    if (direction == down && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        y += speed;
    }
    else if (direction == down)
    {
        direction = up;
        y -= speed;
    }
    if (direction == rightup && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
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
    if (direction == rightdown && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
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
    if (direction == leftup && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
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
    if (direction == leftdown && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
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
void tFigure::rand_move(int speed)
{
    if (direction == right && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x += speed;
    }
    if (direction == left && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x -= speed;
    }
    if (direction == up && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        y -= speed;
    }
    if (direction == down && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        y += speed;
    }
    if (direction == rightup && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x += speed;
        y -= speed;
    }
    if (direction == rightdown && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x += speed;
        y += speed;
    }
    if (direction == leftup && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x -= speed;
        y -= speed;
    }
    if (direction == leftdown && x > width/2 && x < WIDTH - width/2 && y > height/2 && y < HEIGHT - height/2)
    {
        x -= speed;
        y += speed;
    }
    while (x <= width/2 || x >= WIDTH - width/2 || y <= height/2 || y >= HEIGHT - height/2)
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
        if (!(i <= width/2 || i >= WIDTH - width/2 || j <= height/2 || j >= HEIGHT - height/2))
        {
            x = i;
            y = j;
        }
    }
}
void tFigure::draw(sf::RenderWindow &window){}
void tFigure::rotate()
{
    angle+=1;
}

tPoint::tPoint() : tFigure() { width = height = 10; }
tPoint::tPoint(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = height = 10; }
tPoint::~tPoint(){}
void tPoint::draw(sf::RenderWindow &window)
{
    sf::CircleShape point(width / 2);
    point.setFillColor(get_colour());
    point.setPosition(x, y);
    point.setOrigin(width / 2, height / 2);
    point.setRotation(angle);
    window.draw(point);
}

tLine::tLine() : tFigure() { width = 300; height = 2; }
tLine::tLine(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = 300; height = 2; }
tLine::~tLine(){}
void tLine::draw(sf::RenderWindow &window)
{
    sf::RectangleShape line(sf::Vector2f(width, height / 2));
    line.setFillColor(get_colour());
    line.setPosition(x, y);
    line.setOrigin(width / 2, height / 2);
    line.setRotation(angle);
    window.draw(line);
}

tCircle::tCircle() : tFigure() { width = height = 200; }
tCircle::tCircle(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = height = 200; }
tCircle::~tCircle(){}
void tCircle::draw(sf::RenderWindow &window)
{
    sf::CircleShape circle(width / 2);
    circle.setFillColor(get_colour());
    circle.setPosition(x, y);
    circle.setOrigin(width / 2, height / 2);
    circle.setRotation(angle);
    window.draw(circle);
}

tRectangle::tRectangle() : tFigure() { width = 300; height = 100; }
tRectangle::tRectangle(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = 300; height = 100; }
tRectangle::~tRectangle(){}
void tRectangle::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(get_colour());
    rectangle.setPosition(x, y);
    rectangle.setOrigin(width / 2, height / 2);
    rectangle.setRotation(angle);
    window.draw(rectangle);
}

tTriangle::tTriangle() : tFigure() { width = 200; height = 150; }
tTriangle::tTriangle(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = 200; height = 150; }
tTriangle::~tTriangle(){}
void tTriangle::draw(sf::RenderWindow &window)
{
    sf::CircleShape triangle(width / 2);
    triangle.setPointCount(3);
    triangle.setFillColor(get_colour());
    triangle.setPosition(x, y);
    triangle.setOrigin(width / 2, height / 2);
    triangle.setRotation(angle);
    window.draw(triangle);
}

tEllipse::tEllipse() : tFigure() { width = 200; height = 150; }
tEllipse::tEllipse(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = 200; height = 150; }
tEllipse::~tEllipse(){}
void tEllipse::draw(sf::RenderWindow &window)
{
    sf::CircleShape circle(width / 2);
    circle.setScale(1, 0.5);
    circle.setFillColor(get_colour());
    circle.setPosition(x, y);
    circle.setOrigin(width / 2, height / 2);
    circle.setRotation(angle);
    window.draw(circle);
}

tRhombus::tRhombus() : tFigure() { width = 300; height = 200; }
tRhombus::tRhombus(int x, int y, int colour, int direction) : tFigure(x, y, colour, direction) { width = 300; height = 200; }
tRhombus::~tRhombus(){}
void tRhombus::draw(sf::RenderWindow &window)
{
    sf::CircleShape rhombus(width / 2);
    rhombus.setPointCount(4);
    rhombus.setScale(1, 0.5);
    rhombus.setFillColor(get_colour());
    rhombus.setPosition(x, y);
    rhombus.setOrigin(width / 2, height / 2);
    rhombus.setRotation(angle);
    window.draw(rhombus);
}

int main()
{
    srand(time(NULL));
    std::vector<tFigure*> array;
    tPoint p;
    array.push_back(&p);
    tLine l;
    array.push_back(&l);
    tCircle c;
    array.push_back(&c);
    tRectangle r;
    array.push_back(&r);
    tTriangle t;
    array.push_back(&t);
    tEllipse e;
    array.push_back(&e);
    tRhombus h;
    array.push_back(&h);
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "6 lab", sf::Style::Fullscreen);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
                window.close();
        }
        for (auto i = array.begin(); i != array.end(); i++)
        {
            (*i)->draw(window);
        }
        window.display();
        // for (auto i = array.begin(); i != array.end(); i++)
        // {
        //     (*i)->line_move();
        // }
        // for (auto i = array.begin(); i != array.end(); i++)
        // {
        //     (*i)->rand_move();
        // }
        for (auto i = array.begin(); i != array.end(); i++)
        {
            (*i)->rotate();
        }
        window.clear();
    }
    return 0;
}