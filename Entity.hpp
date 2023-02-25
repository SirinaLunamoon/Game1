#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Entity
{
public:
	Entity() {}

	//Bounding box
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;

private:
};