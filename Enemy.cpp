#include "Enemy.hpp"
#include "GenerateRandom.hpp"

Enemy::Enemy() : dir(0), isAlive(true), m_frameCountX(0), m_frameCountY(68), m_timeCount(0), m_hp(50), m_exp(0), m_speed(1.0f), m_attackDamage(5)
{
	rect.setSize(sf::Vector2f(40, 40));
	rect.setFillColor(sf::Color(255, 0, 0));
	rect.setPosition(34, 68);
	sprite.setTextureRect(sf::IntRect(0, 0, 36, 68));
}

void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void Enemy::move()
{
	if (dir == 1)
	{
		rect.move(0.0f, -1.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 34, m_frameCountY * 3, 34, 68));
	}
	else if (dir == 2)
	{
		rect.move(0.0f, 1.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 34, 0, 34, 68));
	}

	else if (dir == 3)
	{
		rect.move(-1.0f, 0.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 34, m_frameCountY * 1, 34, 68));
	}
	else if (dir == 4)
	{
		rect.move(1.0f, 0.0f);
		sprite.setTextureRect(sf::IntRect(m_frameCountX * 34, m_frameCountY * 2, 34, 68));
	}
	else
	{}

	m_frameCountX++;
	if (m_frameCountX == 2)
	{
		m_frameCountX = 0;
	}

	m_timeCount++;
	if (m_timeCount >= 100)
	{
		dir = generateRandomNumber(100);
		m_timeCount = 0;
	}
}