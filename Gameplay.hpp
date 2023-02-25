#pragma once
#include <SFML/Graphics.hpp>

class Gameplay
{
public:
	Gameplay();

	void init();
	void update();
	void draw(sf::RenderWindow &window);
	void destroy();

private:

};