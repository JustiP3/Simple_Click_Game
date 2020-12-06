#include "Game.h"

//Private functions 

void Game::initVariables()
{
	this->window = nullptr;

	//Game Logic 
	this->points = 0;
	this->health = 5;
	this->enemySpawnTimer = 0.f;
	this->enemySpawnTimerMax = 10.f;
	this->maxEnemies = 5;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading font";
	}
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Blue);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(1.f);


}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Simple Click Game", sf::Style::Titlebar | sf::Style::Close);



	// select the font
	this->scoreBoardHealth.setFont(font); // font is a sf::Font

	// set the string to display
	this->scoreBoardHealth.setString("Hello world");

	// set the character size
	this->scoreBoardHealth.setCharacterSize(24); // in pixels, not points!

	// set the color
	this->scoreBoardHealth.setFillColor(sf::Color::Red);

	// set the text style
	this->scoreBoardHealth.setStyle(sf::Text::Bold | sf::Text::Underlined);
		

	this->window->setFramerateLimit(60);
}

// Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

// Public functions

void Game::update()
{
	this->updateEvents();
	this->updateMousePositions();
	this->updateEnemies();
	//std::cout << "Points: " << points << "\n";
}

void Game::render()
{
	this->window->clear();

	//Draw Game Object
	this->renderEnemies();
	this->window->draw(this->scoreBoardHealth);
	this->window->display();
}

void Game::updateMousePositions()
{
	//Updates mouse position relative to window (Vector2i)
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
/*
Updates the Enemy Spawn Timer and Spawns an enemy when the enemy count is less than max. 
Moves enemy position downwards.
Removes enemy at the bottom of the screen. 
*/
{
	
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn Enemy and reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			//Update timer
			this->enemySpawnTimer += 1.f;
		}
	}


	//Itereate and operate on each enemy
	for (int i = 0; i < this->enemies.size(); i++) {

		bool deleted = false;

		//move enemy down
		this->enemies[i].move(0.f, 1.f);

		//checked if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{
				deleted = true; 

				//gain points
				points += 10;
			}
		}

		//check if box hit bottom of screen
		if (this->enemies[i].getPosition().y > this->window->getSize().y - this->enemies[i].getSize().y)
		{
			deleted = true;  

			//Lose points if boxes hit bottom of screen

			points -= 10; 
			health--;
		}

		if (deleted == true)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
	
		
}

void Game::renderEnemies()
{
	//Render each enemy
	for (auto &e : this->enemies) {
		this->window->draw(e);
	}
}


void Game::spawnEnemy()
{
	/*
	Add enemy with random color and position to vector
	*/
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Blue);

	this->enemies.push_back(this->enemy);
}

 //Accessors

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::updateEvents()
{
	//Event Polling

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed :
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}
