#include "engine.h"

class Game
{
	enum GameState { MENU, GAME, GAME_OVER, END };
	GameState state;
public:
	Game(int, int);
	~Game();

	void runGame();
	void me();
	void single();
};