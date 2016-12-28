#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game_object.h"

class Player : public sf::Drawable, sf::Transformable, Game_Object
{
	sf::Texture player;
	sf::Sprite player_r;
	sf::Clock frameTime;
	sf::Clock time;

	int p_width, p_height;
	int p_posx, p_posy;

	//MOTION_PARAMETERS
	float vx = 2.5;
	float g = -1.0, vp = -14, vy = 0;

	//ANIMATIONS
	int act_frame = 0;
	virtual void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const;

	enum StatusX { MOVEX, STOPX };
	enum StatusY { MOVEY, STOPY };

	StatusX statusx;
	StatusY statusy;
	float t;

	bool left = false, right = false, up = false;
	bool ch_s;

public:
	Player(const static int width = 35, const static int height = 55, const static int posx = 80, const static int posy = 420);
	~Player();

	void move();
	void updatex();
	void updatey();

	void stopx();
	void stopy();
	void startxy();
	void change_speed(float speed);

	void fall(); //FALLING
	void play(); //ANIMATIONS

	sf::Vector2f moving();
	sf::Vector2f getPosition();
	sf::FloatRect getBoundingBox();
	sf::Vector2f getSpeed();
	sf::Vector2f getWH();
};
