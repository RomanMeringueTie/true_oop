#include <iostream>
#include <vector>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#define HEIGHT 10
#define WIDTH 10
int mod(int n) { return n > 0 ? n : 0 - n; }

class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(rand() % WIDTH), y(rand() % HEIGHT) {}
    int get_x() { return x; }
    int get_y() { return y; }
    void set_x(int n) { x = n; }
    void set_y(int n) { y = n; }
};

class Creature
{
protected:
    float hunger;
    Point point;

public:
    Creature() : hunger(0)
    {
        point.set_x(rand() % WIDTH);
        point.set_y(rand() % HEIGHT);
    }
    Creature(int x, int y) : hunger(0)
    {
        point.set_x(x);
        point.set_y(y);
    }
    ~Creature()
    {
    }
    int get_x() { return point.get_x(); }
    int get_y() { return point.get_y(); }
    virtual void move() = 0;
};

class Carrot : public Creature
{

public:
    Carrot() : Creature()
    {
    }
    ~Carrot()
    {
    }
    void move()
    {
        point.set_x(rand() % WIDTH);
        point.set_y(rand() % HEIGHT);
    }
};

class Hare : public Creature
{

public:
    Hare() : Creature()
    {
        hunger = 1;
    }
    ~Hare()
    {
    }
    float get_hunger() { return hunger; }
    void set_hunger(float n) { hunger = n; }
    void move()
    {
        int a = rand() % 2;
        int b = rand() % 2;
        while (a + b < 1)
        {
            a = rand() % 2;
            b = rand() % 2;
        }
        int direction = rand() % 2;
        if (direction)
            point.set_x(mod((point.get_x() + a) % WIDTH));
        else
            point.set_x(mod((point.get_x() - a) % WIDTH));
        if (direction)
            point.set_y(mod((point.get_y() + a) % WIDTH));
        else
            point.set_y(mod((point.get_y() - a) % WIDTH));
        hunger -= 0.2;
    }
};

class Wolf : public Creature
{
protected:
    int hare_kills_count;
    bool is_reproduce;

public:
    Wolf() : Creature(), is_reproduce(false)
    {
        hunger = 1;
    }
    ~Wolf()
    {
    }
    float get_hunger() { return hunger; }
    void set_hunger(float n) { hunger = n; }
    void plus_hare_kills_count() { hare_kills_count++; }
    int get_hare_kills_count() { return hare_kills_count; }
    void set_is_reproduce() { is_reproduce = true; }
    bool get_is_reproduce() { return is_reproduce; }
    void move()
    {
        int a = 0;
        int b = 0;
        int direction = 0;
        if (hunger >= 0.5)
        {
            a = rand() % 2;
            b = rand() % 2;
            while (a + b < 1)
            {
                a = rand() % 2;
                b = rand() % 2;
            }
        }
        else
        {
            a = rand() % 3;
            b = rand() % 3;
            while (a + b < 2)
            {
                a = rand() % 3;
                b = rand() % 3;
            }
        }
        direction = rand() % 2;
        if (direction)
            point.set_x(mod((point.get_x() + a) % WIDTH));
        else
            point.set_x(mod((point.get_x() - a) % WIDTH));
        direction = rand() % 2;
        if (direction)
            point.set_y(mod((point.get_y() + a) % WIDTH));
        else
            point.set_y(mod((point.get_y() - a) % WIDTH));
        hunger -= 0.2;
    }
    void draw(sf::RenderWindow &window)
    {
        float array_x[10] = {0, 100, 200, 300, 400, 500, 602, 700, 800, 900};
        float array_y[10] = {5, 105, 205, 302, 402, 502, 600, 700, 800, 900};
        sf::Texture t;
        t.loadFromFile("src/wolf.jpg");
        sf::Sprite s(t);
        s.setPosition(array_x[point.get_x()], array_y[point.get_y()]);
        window.draw(s);
    }
};
