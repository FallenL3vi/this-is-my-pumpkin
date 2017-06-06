#pragma once

#include <SFML/Graphics.hpp>


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
    Player();
    void loadTextures();
    sf::RectangleShape avatarP1;
    sf::Texture playerTexture;
    Pitchfork fork;
};
