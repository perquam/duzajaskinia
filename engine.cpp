#include "engine.h"

Engine::Engine(sf::RenderWindow &window_g)
{

	window = &window_g;

	for (int i = 1; i < Level::COUNT; i++) {
		texture[i].loadFromFile("data/textures/grass.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
	}

	level.loadFromFile("map.level");

	for (int i = 0; i<level.height; i++) {
		for (int j = 0; j<level.width; j++) {
			if (level.level[i][j].type != Level::NONE) {
				sprite[i][j].setTexture(texture[level.level[i][j].type]);
				sprite[i][j].setPosition(j*level.tile_width, i*level.tile_height);
			}
		}
	}

}

Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::runEngine()
{
	bool game = true;
	while (game) {
		sf::Event event_wg;
		while (window->pollEvent(event_wg)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				game = false;
		}

		window->clear(sf::Color::Yellow);

		for (int i = 0; i<level.height; i++)
		{
			for (int j = 0; j<level.width; j++)
			{
				if (level.level[i][j].type != Level::NONE)
					window->draw(sprite[i][j]);
			}
		}

		player.move();

		check_collision();

		player.update();

		window->draw(player);

		window->display();
	}
}

void Engine::check_collision()
{
	if (player.getStatus() == Player::STOP) return;

	sf::FloatRect box1(player.getBoundingBox());

	bool col1 = true;
	bool col2 = true;

	int player_width = 50;
	int player_height = 65;

	int x = box1.left / level.tile_width;
	int y = box1.top / level.tile_height;
	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}

	x = (box1.left + player_width) / level.tile_width;
	y = box1.top / level.tile_height;
	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}

	x = (box1.left) / level.tile_width;
	y = (box1.top + player_height) / level.tile_height;
	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}
	else col1 = false;
	
	x = (box1.left + player_width) / level.tile_width;
	y = (box1.top + player_height) / level.tile_height;
	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}
	else col2 = false;

	if ((col1 == false) && (col2 == false))
		player.fallcheck();
}

