#include "enemy.hpp"
#include "enemy_controls.hpp"
#include "Collision.hpp"

Enemy::Enemy() :
    avatar_enemy({50.f,160.f}),
    enemy_hbox({50.f,40.f})
{
    loadTexture();
    avatar_enemy.setTexture(&enemy_texture);
    avatar_enemy.setOrigin(sf::Vector2f(avatar_enemy.getSize().x/2,avatar_enemy.getSize().y/2));
    enemy_hbox.setOrigin(sf::Vector2f(avatar_enemy.getSize().x/2,avatar_enemy.getSize().y/2));
    avatar_enemy.setPosition(500,300);
    enemy_hbox.setPosition(avatar_enemy.getPosition().x,avatar_enemy.getPosition().y+120);
    Control_E(*this);
    Collision_enemy(*this);
}
void Enemy::loadTexture()
{
    enemy_texture.loadFromFile("graphics/badguy.png");
}

void Enemy::spawnBack()
{
        avatar_enemy.setPosition(spawnPositionx,spawnPositiony);
        enemy_hbox.setPosition(avatar_enemy.getPosition().x,avatar_enemy.getPosition().y+120);
}

void Enemy::flip()
{
    avatar_enemy.scale(-1,1);
}

void Enemy::move(int spdx, int spdy)
{
    avatar_enemy.move(spdx,spdy);
    enemy_hbox.move(spdx,spdy);
}
