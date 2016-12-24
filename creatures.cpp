#include "creatures.h"
#include <Windows.h>

Player::Player()
{
	player.loadFromFile("player.png");
	player_r.setTexture(player);
	player_r.setTextureRect(sf::IntRect(act_frame * 50, 0, 50, 65));
	player_r.setOrigin(0, 0);
	player_r.setPosition(50, 300);
}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(player_r);
}

void Player::play()
{
	player_r.setTextureRect(sf::IntRect(act_frame * 50, 0, 50, 65));
	if (frameTime.getElapsedTime().asSeconds() > 0.1) {
		frameTime.restart();
		act_frame++;
	}
	if (act_frame >= 8) {
		act_frame = 0;
	}
}

void Player::move()
{
	t = time.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			right = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			left = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			up = true;
		}
}

void Player::update()
{
	if (right == true) {

		if (status != FALL)
			status = GO;

		if (player_r.getScale().x < 0) {
			player_r.move(-50, 0);
			player_r.setScale(sf::Vector2f(1, 1));
		}

		if (vx < 0) vx = -vx;

		if (status != FALL) play();
		player_r.move(vx, 0);
		right = false;
	}

	if (left == true) {

		if (status != FALL)
		status = GO;

		if (player_r.getScale().x > 0) {
			player_r.move(50, 0);
			player_r.setScale(sf::Vector2f(-1, 1));
		}

		if (vx > 0) vx = -vx;

		if (status != FALL) play();
		player_r.move(vx, 0);
		left = false;
	}

	if ((up == true) && (status!=FALL)) { status = FALL; vy = vp; }

	if (status == FALL)
		fall();
}

void Player::stop()
{
	status = STOP;

	up = false;

	vy = 0;
}

void Player::fall()
{
		act_frame = 0;
		player_r.setTextureRect(sf::IntRect(act_frame * 50, 0, 50, 65));
		player_r.move(0, vy);
		vy -= g*t * 60;
}

void Player::fallcheck()
{
	status = FALL;
}

sf::Vector2f Player::getPosition()
{
	return player_r.getPosition();
}

Player::Status Player::getStatus()
{
	return status;
}

sf::FloatRect Player::getBoundingBox()
{
	return player_r.getGlobalBounds();
}

sf::Vector2f Player::getSpeed()
{
	return sf::Vector2f(vx, vy);
}