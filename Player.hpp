#pragma once
#include <string>
#include "Entity.hpp"

class Player : public Entity
{
public:
	Player();

	void move();
	void update();
	inline int& getDirection() { return m_dir; }

private:
	int m_frameCountX;
	int m_frameCountY;
	int m_hp;
	int m_exp;
	int m_dir; //1 -> up, 2 -> down, 3 -> left, 4 -> right

	float m_speed;
	float m_attackDamage;
};