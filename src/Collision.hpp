#pragma once
#include "player.hpp"
#include "enemy.hpp"

class Collision_enemy
{
public:

    Enemy &enemy;

    Collision_enemy(Enemy &_enemy);
};

class Collision_player
{
public:

    Player &player;
    Collision_enemy &collision_enemy;

    Collision_player(Player &_player, Collision_enemy &_collision_enemy);

    void collision_move(int speedX, int speedY);
};
