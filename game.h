#include "engine.h"

class Game
{
	enum GameState { MENU, GAME, GAME_OVER, END };
	GameState state;
public:
	Game(int length=1024, int width=576);
	~Game();

	void runGame();
	void me();
	void single();
};