#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Level
{
public:
	Level(std::string filename);
	Level();

	~Level();

	void loadFromFile(std::string filename);

	enum FieldType { NONE, STONE_BRICKS, STONE_BRICKS_W_P, STONE_BRICKS_W_B, STONE_BRICKS_W_W, STONE_BRICKS_W_D, BLACK, EMPTY1, EMPTY2, EMPTY3, EMPTY4,
		EMPTY5, EMPTY6, EMPTY7, EMPTY8, EMPTY9, EMPTY10, EMPTY11, EMPTY12, EMPTY13, EMPTY14, WOODEN_FLOOR, COUNT 
	};

	struct Tile
	{
		FieldType type;
		bool isWall;
	};

	const static int width = 32;
	const static int height = 12;

	const static int tile_width = 1280/width;
	const static int tile_height = 720/height;

	Tile level[height][width];
};