#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	//Private Variables
	//Window
	sf::RenderWindow* window;
	sf::Event event; 
	sf::VideoMode videoMode;

	//Game Object
	sf::RectangleShape enemy;

	//Private functions 
	void initVariables();
	void initWindow();
	void initEnemies();
public:

	// Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors 
	const bool getWindowIsOpen() const;

	// Public functions 
	void updateEvents();
	void update();
	void render();
};

