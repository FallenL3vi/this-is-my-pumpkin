
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    int speed = 10;
    bool direction = 0;
    bool wDirection = 1;
    sf::Event event;

    player.setPosition(100,300);
    player2.setPosition(500,300);
    //grass.setPosition(400,300);

    sf::RenderWindow window( sf::VideoMode( 800, 600, 32 ), "Saw" );
    window.setFramerateLimit(60);
    while( window.isOpen() )
    {
        weapon2.setPosition(player2.getPosition().x,player2.getPosition().y);

        //if(weapon.getGlobalBounds().intersects(weapon2.getGlobalBounds()))
        //{
        // std::cout << "SHIt" << std::endl;
        //  player.move(sf::Vector2f(speed,0));
        //}
        while( window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                window.close();

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
            {
                player.move(sf::Vector2f(0,-speed));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if(direction == 1)
                {
                    player.scale(-1,1);
                    weapon.scale(-1,1);
                    direction = 0;
                    wDirection = 1;
                }
                player.move(sf::Vector2f(speed,0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if(direction == 0)
                {
                    player.scale(-1,1);
                    weapon.scale(-1,1);
                    direction = 1;
                    wDirection = 0;
                }
                player.move(sf::Vector2f(-speed,0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player.move(sf::Vector2f(0,speed));

            }
            weapon.setPosition(player.getPosition().x,player.getPosition().y);

            if((sf::Keyboard::isKeyPressed(sf::Keyboard::X)))
            {
                if(wDirection == 0)
                {
                    weapon.move(sf::Vector2f(-40,0));
                }
                else
                weapon.move(sf::Vector2f(40,0));
            }

            //collison

            if(weapon.getGlobalBounds().intersects(weapon2.getGlobalBounds()))
            {
                player.move(-40,0);
                weapon.move(-40,0);
            }
            if(player.getGlobalBounds().intersects(weapon2.getGlobalBounds()))
            {
                window.close();
            }

            window.clear(sf::Color::White);

            window.draw(player);

            window.draw(player2);
            window.draw(weapon2);
            window.draw(weapon);

            window.display();
        }

    }
}
