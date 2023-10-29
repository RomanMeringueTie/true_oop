#include "life_game.hpp"

// Point
Point::Point(int x, int y) : x(x), y(y) {}
Point::Point() : x(rand() % WIDTH), y(rand() % HEIGHT) {}
Point::~Point() {}
int Point::get_x() { return x; }
int Point::get_y() { return y; }
void Point::set_x(int n) { x = n; }
void Point::set_y(int n) { y = n; }

// Creature
Creature::Creature() : hunger(0)
{
    point.set_x(rand() % WIDTH);
    point.set_y(rand() % HEIGHT);
}
Creature::Creature(int x, int y) : hunger(0)
{
    point.set_x(x);
    point.set_y(y);
}
Creature::~Creature()
{
}
int Creature::get_x() { return point.get_x(); }
int Creature::get_y() { return point.get_y(); }
void Creature::set_x(int n) { point.set_x(n); }
void Creature::set_y(int n) { point.set_y(n); }
void Creature::kill(sf::RenderWindow &window)
{
    float coordinates[10] = {10, 110, 210, 310, 410, 510, 610, 710, 810, 910};
    sf::Texture t;
    t.loadFromFile("src/red.png");
    sf::Sprite s(t);
    s.setPosition(coordinates[get_x()], coordinates[get_y()]);
    window.draw(s);
}

// Carrot
Carrot::Carrot() : Creature(), is_killed(0)
{
}
Carrot::Carrot(int x, int y) : Creature(x, y), is_killed(0) {}
Carrot::~Carrot()
{
}
void Carrot::move()
{
    point.set_x(rand() % WIDTH);
    point.set_y(rand() % HEIGHT);
}
void Carrot::draw(sf::RenderWindow &window)
{
    float coordinates[10] = {10, 110, 210, 310, 410, 510, 610, 710, 810, 910};
    sf::Texture t;
    t.loadFromFile("src/carrot.jpg");
    sf::Sprite s(t);
    s.setPosition(coordinates[get_x()], coordinates[get_y()]);
    window.draw(s);
}
void Carrot::change_is_killed() { is_killed = !is_killed; }
bool Carrot::get_is_killed() { return is_killed; }

// Hare
Hare::Hare() : Creature()
{
    hunger = 1;
}
Hare::Hare(int x, int y) : Creature(x, y) { hunger = 1; }
Hare::~Hare()
{
}
float Hare::get_hunger() { return hunger; }
void Hare::set_hunger(float n) { hunger = n; }
void Hare::move()
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
void Hare::draw(sf::RenderWindow &window)
{
    float coordinates[10] = {10, 110, 210, 310, 410, 510, 610, 710, 810, 910};
    sf::Texture t;
    t.loadFromFile("src/hare.jpg");
    sf::Sprite s(t);
    s.setPosition(coordinates[get_x()], coordinates[get_y()]);
    window.draw(s);
}

// Wolf
Wolf::Wolf() : Creature(), is_reproduce(false)
{
    hunger = 1;
}
Wolf::Wolf(int x, int y) : Creature(x, y), is_reproduce(false) { hunger = 1; }
Wolf::~Wolf()
{
}
float Wolf::get_hunger() { return hunger; }
void Wolf::set_hunger(float n) { hunger = n; }
void Wolf::plus_hare_kills_count() { hare_kills_count++; }
int Wolf::get_hare_kills_count() { return hare_kills_count; }
void Wolf::set_is_reproduce() { is_reproduce = true; }
bool Wolf::get_is_reproduce() { return is_reproduce; }
void Wolf::move()
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
void Wolf::draw(sf::RenderWindow &window)
{
    float coordinates[10] = {10, 110, 210, 310, 410, 510, 610, 710, 810, 910};
    sf::Texture t;
    t.loadFromFile("src/wolf.jpg");
    sf::Sprite s(t);
    s.setPosition(coordinates[get_x()], coordinates[get_y()]);
    window.draw(s);
}

int mod(int n) { return n > 0 ? n : 0 - n; }