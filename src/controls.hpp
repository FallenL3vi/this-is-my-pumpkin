#pragma once
#include "player.hpp"
class Control
{
public:

    int speed_move = 6;
    int range = 50;
    bool direction = 0;
    Control(Player &_player);
    void keyboard();
    Player &player;
};
