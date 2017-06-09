#pragma once

#include <SFML/Graphics.hpp>
#include "enemy.hpp"


class Pitchfork
{
public:

    Pitchfork();
    sf::RectangleShape forkP1;
    sf::Texture forkTexture;
    void loadTextures();
};

class Player
{
public:
    Enemy &enemy;
    Player(Enemy &_enemy);
    void loadTextures();
    int knock_strange = 10;
    sf::RectangleShape avatarP1;
    sf::Texture playerTexture;
    Pitchfork fork;
    void move(int speedX, int speedY, bool direction);
    void flip();
    void attack(int range, bool directions);
};
