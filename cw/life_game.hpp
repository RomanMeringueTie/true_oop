#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define HEIGHT 10
#define WIDTH 10

class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y);
    Point();
    int get_x();
    int get_y();
    void set_x(int n);
    void set_y(int n);
};

class Creature
{
protected:
    float hunger;
    Point point;

public:
    Creature();
    Creature(int x, int y);
    ~Creature();
    int get_x();
    int get_y();
    virtual void move() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    void kill(sf::RenderWindow &window);
};

class Carrot : public Creature
{

public:
    Carrot();
    ~Carrot();
    void move();
    void draw(sf::RenderWindow &window);
};

class Hare : public Creature
{

public:
    Hare();
    ~Hare();
    float get_hunger();
    void set_hunger(float n);
    void move();
    void draw(sf::RenderWindow &window);
};

class Wolf : public Creature
{
protected:
    int hare_kills_count;
    bool is_reproduce;

public:
    Wolf();
    ~Wolf();
    float get_hunger();
    void set_hunger(float n);
    void plus_hare_kills_count();
    int get_hare_kills_count();
    void set_is_reproduce();
    bool get_is_reproduce();
    void move();
    void draw(sf::RenderWindow &window);
};

int mod(int n);