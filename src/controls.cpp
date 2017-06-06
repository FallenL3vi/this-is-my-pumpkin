#include "controls.hpp"

Control::Control(Player &_player) :
    player(_player)
{

}
void Control::keyboard()
{

    player.fork.forkP1.setPosition(player.avatarP1.getPosition());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moving_l(direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moving_r(direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(direction == 0)
        {
            player.avatarP1.move(0,-speed_r);
            player.fork.forkP1.move(0,-speed_r);
        }
        else
        {
            player.avatarP1.move(0,-speed_l);
            player.fork.forkP1.move(0,-speed_l);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(direction == 0)
        {
            player.avatarP1.move(0,speed_r);
            player.fork.forkP1.move(0,speed_r);
        }
        else
        {
            player.avatarP1.move(0,speed_l);
            player.fork.forkP1.move(0,speed_l);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        if(direction == 0)
        {
            player.fork.forkP1.move(40,0);
        }

        if(direction == 1)
        {
            player.fork.forkP1.move(-40,0);
        }
    }
}

void Control::moving_l(bool direct)
{
    speed_r = 0;
    if(direction == 0)
    {
        player.avatarP1.scale(-1,1);
        player.fork.forkP1.scale(-1,1);
        direction = 1;
    }
    if(speed_l != max_speed)
    {
        speed_l += speed_move;
    }
    player.avatarP1.move(-speed_l,0);
    player.fork.forkP1.move(-speed_l,0);
}

void Control::moving_r(bool direct)
{
    speed_l = 0;
    if(direction == 1)
    {
        player.avatarP1.scale(-1,1);
        player.fork.forkP1.scale(-1,1);
        direction = 0;
    }
    if(speed_r != max_speed)
    {
        speed_r += speed_move;
    }
    player.avatarP1.move(speed_r,0);
    player.fork.forkP1.move(speed_r,0);
}
