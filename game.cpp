#include "menu.h"

sf::RenderWindow window;

Game::Game(int length, int width)
{
	window.create(sf::VideoMode(length, width, 32), "Batalia");
	window.setVerticalSyncEnabled(true);
	state = MENU;
}

Game::~Game()
{
}

void Game::runGame()
{
		while (state != END)
		{
			switch (state)
			{
			case GameState::MENU:
				me();
				break;
			case GameState::GAME:
				single();
				break;
			}
	}
}

void Game::me()
{
	Menu menu(window);
	switch (menu.m(1))
	{
	case 2:
		state = END;
		break;
	case 3:
		state = GAME;
		break;
	}
}

void Game::single()
{
	Engine engine(window);
	engine.runEngine();
	state = MENU;
}