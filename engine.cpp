#include "engine.h"
#include <math.h>

Engine::Engine(sf::RenderWindow &window_g)
{

	window = &window_g;

	for (int i = 1; i < Level::COUNT; i++) {
		texture[1].loadFromFile("data/textures/STONE_BRICKS.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[2].loadFromFile("data/textures/STONE_BRICKS_W_P.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[3].loadFromFile("data/textures/STONE_BRICKS_W_B.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[4].loadFromFile("data/textures/STONE_BRICKS_W_W.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[5].loadFromFile("data/textures/STONE_BRICKS_W_D.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[6].loadFromFile("data/textures/BLACK.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
		texture[21].loadFromFile("data/textures/WOODEN_FLOOR.png", sf::IntRect((i - 1)*level.tile_width, 0, level.tile_width, level.tile_height));
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

		sf::Color color(10, 0, 30);
		window->clear(color);

		for (int i = 0; i<level.height; i++)
		{
			for (int j = 0; j<level.width; j++)
			{
				if (level.level[i][j].type != Level::NONE)
					window->draw(sprite[i][j]);
			}
		}

		Game_Object *creature;
		creature = %player;

		creature->move();

		check_collision();

		player.updatex();
		player.updatey();

		window->draw(player);
		window->display();
	}
}

void Engine::check_collision()
{
	sf::FloatRect box1(player.getBoundingBox());

	player.startxy();

	box1.left += player.getSpeed().x / 10;

	//X-axis collisions

	x = (box1.left - 5) / level.tile_width;
	y = box1.top / level.tile_height;

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopx();

	}

	x = (box1.left + level.tile_width - 1) / level.tile_width;
	y = box1.top / level.tile_height;
	
	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopx();
	}

	x = (box1.left - 5) / level.tile_width;
	y = (box1.top + player.getWH().y - 1) / level.tile_height;

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopx();
	}
	
	x = (box1.left + level.tile_width - 1) / level.tile_width;
	y = (box1.top + player.getWH().y - 1) / level.tile_height;

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopx();
	}

	//Y-axis collisions
	box1.left -= player.getSpeed().x / 10;
	box1.top += player.getSpeed().y / 10;

	x = box1.left / level.tile_width;
	y = (box1.top - 10) / level.tile_height;
	fall_ch_t();

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopy();
	}

	x = (box1.left + player.getWH().x - 1) / level.tile_width;
	y = (box1.top - 10) / level.tile_height;
	fall_ch_t();

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopy();
	}

	x = box1.left / level.tile_width;
	y = (box1.top + level.tile_height + 4 + player.getSpeed().y) / level.tile_height;
	fall_ch_b();

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopy();
	}

	x = (box1.left + player.getWH().x - 1) / level.tile_width;
	y = (box1.top + level.tile_height + 4 + player.getSpeed().y) / level.tile_height;
	fall_ch_b();

	if (level.level[y][x].isWall && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stopy();
	}
}

void Engine::fall_ch_b()
{
	sf::FloatRect box1(player.getBoundingBox());

	float distance_bottom = ((box1.top + player.getWH().y) - (sprite[y][x].getGlobalBounds().top));

	if ((-distance_bottom < player.getSpeed().y) && (level.level[y][x].isWall))
	{
		player.change_speed(-distance_bottom);
	}
}

void Engine::fall_ch_t()
{
	sf::FloatRect box1(player.getBoundingBox());

	float distance_top = ((box1.top) - (sprite[y][x].getGlobalBounds().top + level.tile_height));

	if ((distance_top < -player.getSpeed().y) && (level.level[y][x].isWall))
	{
		player.change_speed(distance_top);
	}
}

