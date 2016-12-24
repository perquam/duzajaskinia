#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"

class Menu
{
	sf::RenderWindow *window;
	sf::Texture background;
	sf::Sprite background_r;
	sf::Font font;
	sf::Text title;
	sf::Text credits[2];
	animation *animation_pointer;
	Fire fire_menu;
	Soundtrack menu_m;
	enum GameState { MENU, GAME, END };
	GameState state;
public:
	Menu(sf::RenderWindow &window_m);
	Menu();
	~Menu();
	int m(int a);
};