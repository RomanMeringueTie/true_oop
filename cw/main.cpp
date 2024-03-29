#include "life_game.hpp"

int main()
{
    srand(time(NULL));
    int WolfKills = 0;
    int HareKills = 0;
    int WolfHungerDies = 0;
    int HareHungerDies = 0;
    int Timer = 0;
    int living_cycle = 0;
    int hares_rand = 0;
    sf::Texture t;
    t.loadFromFile("src/fon.png");
    sf::Sprite s(t);
    Carrot c;
    Hare h;
    std::vector<Hare> hares;
    hares.push_back(h);
    std::vector<Wolf> wolfs;
    while (wolfs.size() != 5)
    {
        Wolf w;
        wolfs.push_back(w);
    }
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Life Game");
    while (window.isOpen())
    {
        int MissingWolfCount = 0;
        while (wolfs.size() < 5)
        {
            MissingWolfCount++;
            Wolf w;
            wolfs.push_back(w);
        }
        if (MissingWolfCount)
            std::cout << MissingWolfCount << " Wolfs appeared!" << std::endl;
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Timer++;
        living_cycle++;
        window.draw(s);
        for (size_t i = 0; i < wolfs.size(); i++)
        {
            wolfs[i].draw(window);
        }
        for (size_t i = 0; i < hares.size(); i++)
        {
            hares[i].draw(window);
        }
        if (!c.get_is_killed())
            c.draw(window);
        window.display();
        if (living_cycle % 3 == 0)
        {
            hares_rand = rand() % 4;
            if (hares_rand == 3)
            {
                Hare tmp;
                hares.push_back(tmp);
                Hare h = hares[rand() % hares.size()];
                h.set_hunger(h.get_hunger() - 0.4);
                tmp.draw(window);
                std::cout << "Hare appeared!" << std::endl;
            }
            for (size_t i = 0; i < hares.size(); i++)
            {
                if (hares[i].get_hunger() > 0.1)
                    hares[i].move();
                else
                {
                    auto iter = hares.cbegin();
                    hares[i].kill(window);
                    hares.erase(iter + i);
                    std::cout << "Hare died of hunger!" << std::endl;
                    HareHungerDies++;
                }
            }
            for (size_t i = 0; i < wolfs.size(); i++)
            {
                if (wolfs[i].get_hunger() > 0.1)
                    wolfs[i].move();
                else
                {
                    auto iter = wolfs.cbegin();
                    wolfs[i].kill(window);
                    wolfs.erase(iter + i);
                    std::cout << "Wolf died of hunger!" << std::endl;
                    WolfHungerDies++;
                }
            }
        }
        for (size_t i = 0; i < hares.size(); i++)
        {
            if (hares[i].get_x() == c.get_x() && hares[i].get_y() == c.get_y())
            {
                hares[i].set_hunger(hares[i].get_hunger() + 0.2);
                c.change_is_killed();
                std::cout << "Carrot killed" << std::endl;
                HareKills++;
            }
        }
        for (size_t i = 0; i < wolfs.size(); i++)
        {
            for (size_t j = 0; j < hares.size(); j++)
            {
                if (wolfs[i].get_x() == hares[j].get_x() && wolfs[i].get_y() == hares[j].get_y())
                {
                    wolfs[i].set_hunger(wolfs[i].get_hunger() + 0.2);
                    auto iter = hares.cbegin();
                    hares.erase(iter + j);
                    std::cout << "Hare killed" << std::endl;
                    WolfKills++;
                    wolfs[i].plus_hare_kills_count();
                    if (wolfs[i].get_hare_kills_count() >= 2 && wolfs[i].get_is_reproduce() == false)
                    {
                        Wolf w;
                        wolfs.push_back(w);
                        w.draw(window);
                        wolfs[i].set_hunger(wolfs[i].get_hunger() - 0.4);
                        std::cout << "Wolf appeared!" << std::endl;
                    }
                }
            }
        }
        if (living_cycle % 5 == 0)
        {
            if (c.get_is_killed())
                c.change_is_killed();
            else
                c.kill(window);
            c.move();
            std::cout << "Carrot appeared!" << std::endl;
        }
        window.display();
        sleep(1);
    }
    std::cout << "Game lasted " << Timer << " seconds" << std::endl
              << "Hares killed carrots " << HareKills << " times" << std::endl
              << "Wolfs killed hares " << WolfKills << " times" << std::endl
              << "Hares starved to death " << HareHungerDies << " times" << std::endl
              << "Wolfs starved to death " << WolfHungerDies << " times" << std::endl;
}
