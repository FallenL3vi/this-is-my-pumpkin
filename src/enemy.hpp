#pragma once
#include "SFML/Graphics.hpp"

class Enemy
{
public:

    Enemy();
    sf::RectangleShape avatar_enemy;
    sf::Texture enemy_texture;

    void loadTexture();
    void knockBack(bool direction,int knock_range);
};
