#include "Collision.hpp"
#include "player.hpp"
#include "enemy.hpp"

Collision_enemy::Collision_enemy(Enemy &_enemy) :
    enemy(_enemy)
{

}

Collision_player::Collision_player(Player&_player, Collision_enemy &_collision_enemy) :
    player(_player),
    collision_enemy(_collision_enemy)
{

}

void Collision_player::collision_move(int speedX, int speedY)
{
    if(player.avatar_hbox.getGlobalBounds().intersects(collision_enemy.enemy.enemy_hbox.getGlobalBounds()))
    {
        player.avatarP1.move(-(speedX),-(speedY));
        player.avatar_hbox.move(-(speedX),-(speedY));
        player.fork.fork_hbox.move(-(speedX),-(speedY));
        player.fork.forkP1.move(-(speedX),-(speedY));
    }
}
