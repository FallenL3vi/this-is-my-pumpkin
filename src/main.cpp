#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "controls.hpp"
#include "enemy.hpp"

int main()
{
    Player player;
    Enemy enemy;
    Control control(player);
    sf::Event event;

    sf::Texture back;
    back.loadFromFile("graphics/background.png");
    sf::RectangleShape backg({800,600});
    backg.setTexture(&back);

    sf::RenderWindow window( sf::VideoMode(800,600),"Game alpha 0.01v");
    {

        window.setFramerateLimit(60);
        while(window.isOpen())
        {
            while( window.pollEvent( event ) )
            {
                if( event.type == sf::Event::Closed )
                    window.close();

                if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            window.clear(sf::Color::White);
            window.draw(backg);
            window.draw(player.avatarP1);
            window.draw(enemy.avatar_enemy);
            window.draw(player.fork.forkP1);
            control.keyboard();
            window.display();
        }
    }
}
