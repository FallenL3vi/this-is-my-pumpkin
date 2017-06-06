#pragma once
#include "player.hpp"
class Control
{
public:

    int speed_move = 1;
    int speed_l = 0;
    int speed_r = 0;
    int max_speed = 6;
    bool direction = 0;
    Control(Player &_player);
    void keyboard();
    void moving_l(bool direct);
    void moving_r(bool direct);
    Player &player;
};
