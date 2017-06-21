#pragma once

#include <SFML/Graphics.hpp>
#include "enemy.hpp"


class Pitchfork
{
public:

    Pitchfork();
    sf::RectangleShape forkP1;
    sf::RectangleShape fork_hbox;
    sf::Texture forkTexture;
    sf::Texture foTexture;
    void loadTextures();
};

class Player
{
public:

    Player();
    void loadTextures();
    int knock_strange = 100;
    sf::RectangleShape avatarP1;
    sf::RectangleShape avatar_hbox;
    sf::Texture playerTexture;
    Pitchfork fork;
    void move(int speedX, int speedY, bool direction);
    void flip();
    void attack(int range, bool directions);
};
