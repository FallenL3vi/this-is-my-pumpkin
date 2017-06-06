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

Player::Player()  :
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
