#pragma once
#include "enemy.hpp"

class Control_E
{
public:

    int speed_move = 8;
    bool direction = 1;
    Enemy &enemy;
    Control_E(Enemy &_enemy);
    void keyboard();
};
