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

	enum FieldType { NONE, GRASS, COUNT};

	struct Tile
	{
		FieldType type;
		bool isWall;
	};

	const static int width = 32;
	const static int height = 18;

	const static int tile_width = 32;
	const static int tile_height = 32;

	Tile level[height][width];
};