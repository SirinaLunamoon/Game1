#pragma once
#include "Entity.hpp"
#include "Player.hpp"

class Bullet : public Entity
{
public:
	Bullet();

	void fire();
	void update();

	inline int& getDirection() { return m_dir; }

public:

private:
	int m_dir; //1 -> up, 2 -> down, 3 -> left, 4 -> right
	float m_speed;
};