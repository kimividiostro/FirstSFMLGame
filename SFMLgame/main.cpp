#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML game");
    sf::CircleShape player(100.f);
    player.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.move(-1, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.move(1, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                player.move(0.0f, -1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                player.move(0.0f, 1);
            }
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}