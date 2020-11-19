#include "Game.h"

//Private functions 

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Simple Click Game", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Public functions

void Game::update()
{
	this->updateEvents();
}

void Game::render()
{
	this->window->clear(sf::Color::Blue);
	this->window->display();
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