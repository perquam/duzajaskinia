#include "objects.h"

void Soundtrack::music_play()
{
	music.openFromFile("menu.ogg");
	music.play();
	music.setLoop(true);
}

void Soundtrack::music_stop()
{
	music.stop();
}

void Fire::load(int xfire, int yfire)
{
	flame.loadFromFile("flame.png");
	fire.loadFromFile("fire.png");
	fire_a.setTexture(fire);
	fire_a.setOrigin(39, 78);
	fire_a.setScale(2, 2);
	for (int i = 0; i < f_amount; i++) {
		flame_r[i].setTexture(flame);
		flame_r[i].setOrigin(15, 15);
		flame_r[i].setPosition(xfire, yfire);
	}
}

void Fire::play(int xfire, int yfire, sf::RenderWindow &window)
{
	for (int i = 0; i < f_amount; i++)
		window.draw(flame_r[i]);
	wind(xfire, yfire);
	fire_a.setPosition(xfire, yfire);
	window.draw(fire_a);
	fire_a.setTextureRect(sf::IntRect(act_frame * 78, 0, 78, 156));
	if (frameTime.getElapsedTime().asSeconds() > 0.08) {
		frameTime.restart();
		act_frame++;
	}
	if (act_frame >= 9) {
		act_frame = 0;
	}
}

void Fire::wind(int xfire, int yfire)
{
	srand(time(NULL));
	int x, y, z;
	for (int i = 0; i < f_amount; i++) {
		x = rand() % 4 + 1;
		y = rand() % 5 + 3;
		z = rand() % 10;
		if (z == 0)
			x = x*(-1);
		float a = x, b = y, c = z;

		int s;
		s = rand() % 3;
		if (s == 0) s = -1; else if (s == 1) s = 1; else s = 0;

		flame_r[i].move(a, -b);
		flame_r[i].setScale(1 + s*0.1, 1 + s*0.1);

		if (flame_r[i].getPosition().y<0) {
			flame_r[i].setPosition(xfire, yfire);
		}
	}
}