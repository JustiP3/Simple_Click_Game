#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class Game
{
private:
	//Private Variables
	//Window
	sf::RenderWindow* window;
	sf::Event event; 
	sf::VideoMode videoMode;

	//Mouse Position
	sf::Vector2i mousePosWindow;

	//Game Object
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	//Game Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

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
	void spawnEnemy();

	void updateEvents();
	void updateMousePositions();
	void update();
	void updateEnemies();
	void render();
	void renderEnemies(); 
};

