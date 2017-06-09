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
    void moving_l(bool direct);
    void moving_r(bool direct);
    Player &player;
};
