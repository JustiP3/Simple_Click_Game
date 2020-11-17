#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    // Severity	Code	Description	Project	File	Line	Suppression State
    //Error	LNK1112	module machine type 'x86' conflicts with target machine type 'x64'	Simple_Click_Game	 : 
    //\Users\justi\source\repos\Simple_Click_Game\Simple_Click_Game\sfml - graphics - d.lib(sfml - graphics - d - 2.dll)	1

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}