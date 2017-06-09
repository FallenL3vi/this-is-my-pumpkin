#include "player.hpp"
#include "controls.hpp"

Pitchfork::Pitchfork() :
    forkP1({160.f,50.f})
{
    loadTextures();
    forkP1.setTexture(&forkTexture);
    forkP1.setOrigin(sf::Vector2f(forkP1.getSize().x/2,forkP1.getSize().y/2));
    forkP1.setPosition(400,300);
}

void Pitchfork::loadTextures()
{
    forkTexture.loadFromFile("graphics/fork.png");
}

Player::Player(Enemy &_enemy)  :
    enemy(_enemy),
    avatarP1({50.f,160.f}),
    fork()
{
    loadTextures();
    avatarP1.setTexture(&playerTexture);
    avatarP1.setOrigin(sf::Vector2f(avatarP1.getSize().x/2,avatarP1.getSize().y/2));
    avatarP1.setPosition(400,300);
    Control(*this);
}

void Player::loadTextures()
{
    playerTexture.loadFromFile("graphics/player.png");
}

void Player::move(int speedX, int speedY, bool dire)
{
    avatarP1.move(speedX,speedY);
    fork.forkP1.move(speedX,speedY);

    if(fork.forkP1.getGlobalBounds().intersects(enemy.avatar_enemy.getGlobalBounds()))
    {
    enemy.knockBack(dire,knock_strange);
    }

    if(avatarP1.getGlobalBounds().intersects(enemy.avatar_enemy.getGlobalBounds()))
    {
     avatarP1.move(-(speedX),-(speedY));
     fork.forkP1.move(-(speedX),-(speedY));
    }
}

void Player::flip()
{
    avatarP1.scale(-1,1);
    fork.forkP1.scale(-1,1);
}

void Player::attack(int range, bool dire)
{
    if(dire == 0)
    {
        fork.forkP1.move(range,0);

        if(fork.forkP1.getGlobalBounds().intersects(enemy.avatar_enemy.getGlobalBounds()))
        {
            enemy.knockBack(dire,knock_strange);
        }
    }

    if(dire == 1)
    {
        fork.forkP1.move(-range,0);

        if(fork.forkP1.getGlobalBounds().intersects(enemy.avatar_enemy.getGlobalBounds()))
        {
            enemy.knockBack(dire,knock_strange);
        }
    }
}
