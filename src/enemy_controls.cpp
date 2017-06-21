#include "enemy_controls.hpp"

Control_E::Control_E(Enemy& _enemy) :
    enemy(_enemy)
{

}

void Control_E::keyboard()
{


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(direction == 0)
        {
            enemy.flip();
            direction = 1;
        }
        enemy.avatar_enemy.move(-speed_move,0);
        enemy.enemy_hbox.move(-speed_move,0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(direction == 1)
        {
            enemy.flip();
            direction = 0;
        }
        enemy.avatar_enemy.move(speed_move,0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        enemy.avatar_enemy.move(0,-speed_move);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        enemy.avatar_enemy.move(0,speed_move);
    }
}
