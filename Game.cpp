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
}

void Game::render()
{
}
