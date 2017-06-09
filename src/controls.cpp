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
        if(direction == 0)
        {
            player.flip();
            direction = 1;
        }
        player.move(-speed_move,0,direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(direction == 1)
        {
            player.flip();
            direction = 0;
        }
        player.move(speed_move,0,direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move(0,-speed_move,direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0,speed_move,direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        player.attack(range, direction);
    }
}
