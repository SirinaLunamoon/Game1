#include "Player.hpp"

Player::Player() : m_dir(0), m_frameCountX(0), m_frameCountY(32), m_hp(100), m_exp(0), m_speed(0.2f), m_attackDamage(10.0f)
{
	rect.setSize(sf::Vector2f(30, 40));
	rect.setFillColor(sf::Color(0, 0, 255));
	rect.setPosition(400, 200);

	sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
	sprite.setScale(1.8f, 1.8f);
}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0.0f, -m_speed);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 21, m_frameCountY * 0, 21, 32));
		m_dir = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0.0f, m_speed);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 21, m_frameCountY * 2, 21, 32));
		m_dir = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-m_speed, 0.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 21, m_frameCountY * 3, 21, 32));
		m_dir = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(m_speed, 0.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 21, m_frameCountY * 1, 21, 32));
		m_dir = 4;
	}

	m_frameCountX++;
	if (m_frameCountX == 2)
	{
		m_frameCountX = 0;
	}
}