#include "player.hpp"
#include "SFML/Graphics.hpp"

class Enemy
{
public:

    Enemy();
    sf::RectangleShape avatar_enemy;
    sf::Texture enemy_texture;

    void loadTexture();
};
