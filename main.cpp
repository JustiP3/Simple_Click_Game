#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
 
    // Configure Window
    sf::RenderWindow window(sf::VideoMode(640, 580), "Simple Click Game", sf::Style::Titlebar | sf::Style::Close);

    //Test Circle Object
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }
           

        //Update

        //Render 
        window.clear();
        window.draw(shape);
        window.display();
    }

    // End of application 
    return 0;
}