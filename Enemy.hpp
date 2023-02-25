#pragma once
#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy();

	void update();
	void move();

	int& getHp() { return m_hp; }

public:
	int dir; //1 -> up, 2 -> down, 3 -> left, 4 -> right
	bool isAlive;

private:
	int m_frameCountX;
	int m_frameCountY;
	//How much time eney need to change their direction
	int m_timeCount;

	int m_hp;
	int m_exp;

	float m_speed;
	float m_attackDamage;
};