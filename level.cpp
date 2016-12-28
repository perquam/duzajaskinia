#include "level.h"

Level::Level(std::string filename)
{
		loadFromFile(filename);
}

Level::Level()
{
}

Level::~Level()
{
}

void Level::loadFromFile(std::string filename)
{
	std::fstream file;
	file.open("data/levels/" + filename, std::ios::in);

		for (int y = 0; y<height; y++)
			for (int x = 0; x < width; x++)
			{
				int tmp;
				file >> tmp;
				level[y][x].type = FieldType(tmp);

				if (tmp < 21)
					level[y][x].isWall = false;
				else
					level[y][x].isWall = true;
			}

	file.close();
}