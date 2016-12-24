#include "creatures.h"
#include "objects.h"
#include "level.h"

class Engine
{
	sf::RenderWindow *window;
	Level level;
	Player player;

	sf::Texture texture[Level::COUNT];
	sf::Sprite sprite[Level::height][Level::width];

public:
	Engine(sf::RenderWindow &window_g);
	Engine();
	~Engine();

	void runEngine();
	void check_collision();
};