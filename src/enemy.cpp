#include "enemy.hpp"

Enemy::Enemy() :
    avatar_enemy({50.f,160.f})
{
    loadTexture();
    avatar_enemy.setTexture(&enemy_texture);
    avatar_enemy.setOrigin(sf::Vector2f(avatar_enemy.getSize().x/2,avatar_enemy.getSize().y/2));
    avatar_enemy.setPosition(500,300);
    Enemy(*this);
}
void Enemy::loadTexture()
{
    enemy_texture.loadFromFile("graphics/badguy.png");
}

void Enemy::knockBack(bool direct,int knock_range)
{
    if(direct == 0)
    {
        avatar_enemy.move(knock_range,0);
    }
    if(direct == 1)
    {
        avatar_enemy.move(-knock_range,0);
    }
}
