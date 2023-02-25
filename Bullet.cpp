#include "Bullet.hpp"

Bullet::Bullet() : m_dir(0), m_speed(10.0f)
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color(0, 0, 255));
}

void Bullet::update()
{
	sprite.setPosition(rect.getPosition());
}

void Bullet::fire()
{
	if (m_dir == 1)
	{
		rect.move(0.0f, -m_speed);
	}
	else if (m_dir == 2)
	{
		rect.move(0.0f, m_speed);
	}
	else if (m_dir == 3)
	{
		rect.move(-m_speed, 0.0f);
	}
	else if (m_dir == 4)
	{
		rect.move(m_speed, 0.0f);
	}
}
