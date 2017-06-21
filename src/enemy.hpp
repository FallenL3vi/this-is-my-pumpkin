#pragma once
#include "SFML/Graphics.hpp"

class Enemy
{
public:

    Enemy();
    sf::RectangleShape avatar_enemy;
    sf::RectangleShape enemy_hbox;
    sf::Texture enemy_texture;
    int spawnPositionx = 1900;
    int spawnPositiony = 500;


    void loadTexture();
    void spawnBack();
    void flip();
    void move(int spdx, int spdy);
};
