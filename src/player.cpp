#include "player.hpp"
#include "controls.hpp"
#include "enemy_controls.hpp"
#include "Collision.hpp"

Pitchfork::Pitchfork() :
    forkP1({160.f,50.f}),
    fork_hbox({50.f,50.f})
{
    loadTextures();
    forkP1.setTexture(&forkTexture);
    fork_hbox.setTexture(&foTexture);
    forkP1.setOrigin(sf::Vector2f(forkP1.getSize().x/2,forkP1.getSize().y/2));
    fork_hbox.setOrigin(sf::Vector2f(forkP1.getSize().x/2 - 110,forkP1.getSize().y/2));
    forkP1.setPosition(400,300);
    fork_hbox.setPosition(forkP1.getPosition().x, forkP1.getPosition().y);
}

void Pitchfork::loadTextures()
{
    forkTexture.loadFromFile("graphics/fork.png");
    foTexture.loadFromFile("graphics/a.png");
}

Player::Player()  :
    avatarP1({50.f,160.f}),
    avatar_hbox({30.f,30.f}),
    fork()
{
    loadTextures();
    avatarP1.setTexture(&playerTexture);
    avatarP1.setOrigin(sf::Vector2f(avatarP1.getSize().x/2,avatarP1.getSize().y/2));
    avatarP1.setPosition(400,300);
    avatar_hbox.setOrigin(sf::Vector2f(avatarP1.getSize().x/2, avatarP1.getSize().y/2));
    avatar_hbox.setPosition(avatarP1.getPosition().x+10, avatarP1.getPosition().y+130);
    Control(*this);
    Collision_player(*this);
}

void Player::loadTextures()
{
    playerTexture.loadFromFile("graphics/player.png");
}

void Player::move(int speedX, int speedY, bool dire)
{
    avatarP1.move(speedX,speedY);
    avatar_hbox.move(speedX,speedY);
    fork.fork_hbox.move(speedX,speedY);
    fork.forkP1.move(speedX,speedY);
    Collision_player.collision_move(speedX,speedY);
}

void Player::flip()
{
    avatarP1.scale(-1,1);
    fork.forkP1.scale(-1,1);
    fork.fork_hbox.scale(-1,1);
}

void Player::attack(int range, bool dire)
{
    if(dire == 0)
    {
        fork.forkP1.move(range,0);
        fork.fork_hbox.move(range,0);
    }

    if(dire == 1)
    {
        fork.forkP1.move(-range,0);
        fork.fork_hbox.move(-range,0);
    }
}
