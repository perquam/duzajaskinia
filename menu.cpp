#include "menu.h"

Menu::Menu(sf::RenderWindow &window_m)
{
	window = &window_m;
}

Menu::Menu()
{
}

Menu::~Menu()
{
}

int Menu::m(int a)
{
	srand(time(NULL));
	int xfire = 550, yfire = 250;
	background.loadFromFile("background.png");
	background_r.setTexture(background);
	font.loadFromFile("ENDOR___.ttf");
	title.setString(L"Batalia");
	title.setCharacterSize(100);
	title.setFont(font);
	title.setFillColor(sf::Color::Red);
	title.setPosition(340, 50);

	fire_menu.load(xfire, yfire);

	credits[0].setString(L"PLAY");
	credits[1].setString(L"EXIT");

	for (int i = 0; i < 2; i++) {
		credits[i].setCharacterSize(60);
		credits[i].setFont(font);
		credits[i].setFillColor(sf::Color::Red);
		credits[i].setPosition(340, 250 + 150 * i);
	}

	menu_m.music_play();

	while (a == 1) {
		sf::Vector2f mouse(sf::Mouse::getPosition(*window));
		sf::Event event_w;
		while (window->pollEvent(event_w)) {
			if (event_w.type == sf::Event::Closed) {
				a = 2;
				return a;
			}
			else if ((credits[1].getGlobalBounds().contains(mouse)) && (event_w.type == sf::Event::MouseButtonReleased) && (event_w.key.code == sf::Mouse::Left)) {
				credits[1].setScale(1.2, 1.2);
				Sleep(100);
				a = 2;
				return a;
			}
			else if ((credits[0].getGlobalBounds().contains(mouse)) && (event_w.type == sf::Event::MouseButtonReleased) && (event_w.key.code == sf::Mouse::Left)) {
				credits[0].setScale(1.2, 1.2);
				Sleep(100);
				a = 3;
				return a;
			}
		}

		for (int i = 0; i < 2; i++) {
			if (credits[i].getGlobalBounds().contains(mouse)) {
				xfire = 550; yfire = 250 + 150 * i;
				credits[i].setFillColor(sf::Color::Yellow);
			}
			else credits[i].setFillColor(sf::Color::Red);
		}

		window->clear();

		window->draw(background_r);

		animation_pointer = &fire_menu;
		animation_pointer->play(xfire, yfire, *window);

		window->draw(title);
		for (int i = 0; i < 2; i++)
			window->draw(credits[i]);

		window->display();
	}
}