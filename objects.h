#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

class Soundtrack
{
	sf::Music music;
public:
	void music_play();
	void music_stop();
};

class animation
{
public:
	virtual void play(int xfire, int yfire, sf::RenderWindow &window) = 0;
};

class Fire :public animation
{
protected:
	sf::Texture flame, fire;
	sf::Sprite flame_r[20], fire_a;
	sf::Clock frameTime;
	int act_frame = 0;
	int f_amount = 20;
public:
	void load(int xfire, int yfire);
	void wind(int xfire, int yfire);
	virtual void play(int xfire, int yfire, sf::RenderWindow &window);
};
