#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Game
{
private:
	//Private Variables
	sf::RenderWindow* window;
	sf::Event event; 
	sf::VideoMode videoMode;

	//Private functions 
	void initVariables();
	void initWindow();

public:

	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Public functions 
	void update();
	void render();
};

