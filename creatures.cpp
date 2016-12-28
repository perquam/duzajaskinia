#include "creatures.h"
#include <Windows.h>

Player::Player(const static int width, const static int height, const static int posx, const static int posy)
{
	p_width = width;
	p_height = height;
	p_posx = 80;
	p_posy = 420;
	player.loadFromFile("player.png");
	player_r.setTexture(player);
	player_r.setTextureRect(sf::IntRect(p_width, 0, p_width, p_height));
	player_r.setOrigin(0, p_height - 1);
	player_r.setPosition(p_posx, p_posy);
}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(player_r);
}

void Player::move()
{
	t = time.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			right = true;
			if (vx < 0) vx = -vx;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			left = true;
			if (vx > 0) vx = -vx;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			up = true;
			if (statusy==STOPY) vy = vp;
		}

		if ((statusy == MOVEY) && ch_s != true)
			fall();

		ch_s = false;
}

void Player::startxy()
{
	statusx = MOVEX;
	statusy = MOVEY;
}

void Player::stopx()
{
	statusx = STOPX;
}

void Player::stopy()
{
	statusy = STOPY;
	vy = 0;
}

void Player::change_speed(float speed)
{
	vy = speed;
	ch_s = true;
}

void Player::updatex()
{
	if (statusx != STOPX)
	{
		if (right == true) {
			if (player_r.getScale().x < 0) {
				player_r.move(-p_width, 0);
				player_r.setScale(sf::Vector2f(1, 1));
			}

			if (statusy != MOVEY) play();
			player_r.move(vx, 0);
			right = false;
		}

		if (left == true) {
			if (player_r.getScale().x > 0) {
				player_r.move(p_width, 0);
				player_r.setScale(sf::Vector2f(-1, 1));
			}

			if (statusy != MOVEY) play();
			player_r.move(vx, 0);
			left = false;
		}
	}
}

void Player::updatey()
{
	if (statusy != STOPY)
	{
		player_r.move(0, vy);
	}
}

void Player::fall()
{
	player_r.setTextureRect(sf::IntRect(p_width, 0, p_width, p_height));

	int vmax = 6;
	if ((vy < vmax) || (vy>-vmax))
		vy -= g*t * 60;
	else if (vy >= vmax)
		vy = vmax;
	else vy = -vmax;
}

void Player::play()
{
	player_r.setTextureRect(sf::IntRect(act_frame * p_width, 0, p_width, p_height));
	if (frameTime.getElapsedTime().asSeconds() > 0.15) {
		frameTime.restart();
		act_frame++;
	}
	if (act_frame > 3) {
		act_frame = 0;
	}
}

sf::Vector2f Player::getPosition()
{
	return player_r.getPosition();
}

sf::FloatRect Player::getBoundingBox()
{
	return player_r.getGlobalBounds();
}

sf::Vector2f Player::getSpeed()
{
	return sf::Vector2f(vx, vy);
}

sf::Vector2f Player::getWH()
{
	return sf::Vector2f(p_width, p_height);
}