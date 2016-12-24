#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player : public sf::Drawable, sf::Transformable
{
public:
	Player();
	~Player();

	enum Status { MOVEX, MOVEY, STOPX, STOPY };

	void play();
	void move();
	void updatex();
	void updatey();

	void go();
	void stopx();
	void stopy();
	void fall();
	void startxy();
	sf::Vector2f moving();

	sf::Vector2f getPosition();
	Status getStatus();
	sf::FloatRect getBoundingBox();
	sf::Vector2f getSpeed();
private:
	sf::Texture player;
	sf::Sprite player_r;
	sf::Clock frameTime;
	sf::Clock time;

	//MOVE_SPEED
	int vx = 3;

	//FALLING
	float g = -1.4, vp = -16.7, vy = 0;

	//ANIMATIONS
	int act_frame = 0;
	virtual void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const;

	Status status;
	float pos1;
	float pos2;
	float t;

	bool left=false, right=false, up=false;
};
