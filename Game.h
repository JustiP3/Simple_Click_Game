#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>

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
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font; 

	//Text
	sf::Text uiText;

	//Game Object
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;
	sf::Text scoreBoardHealth;
	sf::Text scoreBoardPoints;

	//Game Logic
	bool endGame;
	int points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;

	//Private functions 
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();
public:

	// Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors 
	const bool getWindowIsOpen() const;
	const bool getEndGame() const;

	// Public functions 
	void spawnEnemy();

	void updateEvents();
	void updateMousePositions();
	void updateEnemies();
	void updateText();
	void update();
	
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
	
};

