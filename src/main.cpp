#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "controls.hpp"
#include "enemy.hpp"
#include "enemy_controls.hpp"

int main()
{
    Enemy enemy;
    Player player;
    Control control(player);
    Control_E control_e(enemy);
    sf::Event event;

    sf::Texture back;
    back.loadFromFile("graphics/background.png");
    sf::RectangleShape backg({2000,1000});
    backg.setTexture(&back);
    sf::View view(sf::FloatRect(0, 0, 2000, 1000));
    sf::RenderWindow window( sf::VideoMode(1400,900),"Game alpha 0.01v", sf::Style::Titlebar);
    {
        window.setFramerateLimit(60);
        window.setView(view);
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
            if(player.avatarP1.getPosition().y > enemy.avatar_enemy.getPosition().y)
            {
            window.draw(enemy.avatar_enemy);
            window.draw(player.avatarP1);
            window.draw(player.fork.forkP1);
            window.draw(player.fork.fork_hbox);
            }
            else
            {
            window.draw(player.avatarP1);
            window.draw(player.fork.forkP1);
            window.draw(player.fork.fork_hbox);
            window.draw(enemy.avatar_enemy);
            }
            control.keyboard();
            control_e.keyboard();

            window.display();
        }
    }
}
