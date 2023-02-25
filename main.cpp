#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

int main()
{
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;
	int depth = 32;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, depth), "Game1");

	//Set the icon
	sf::Image icon;
	if (!icon.loadFromFile("res/Icon.png"))
	{
		exit(-1);
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//Load a sprite to display
	sf::Texture playerTex;
	if (!playerTex.loadFromFile("res/Player.png"))
	{
		exit(-2);
	}
	
	sf::Texture bulletTex;
	if (!bulletTex.loadFromFile("res/Bullet.png"))
	{
		exit(-3);
	}

	sf::Texture enemyTex;
	if (!enemyTex.loadFromFile("res/Zombie_n_skeleton2.png"))
	{
		exit(-4);
	}

	//Load text to display
	sf::Font font;
	if (!font.loadFromFile("res/Architex.ttf"))
	{
		exit(-5);
	}
	sf::Text text("Test text", font, 40);
	text.setFillColor(sf::Color(255, 255, 255));

	//Load music to play
	sf::Music music;
	if (!music.openFromFile("res/TestCrunk.ogg"))
	{
		exit(-5);
	}

	//Play music
	//music.play();

	Player player;
	player.sprite.setTexture(playerTex);
	
	std::vector<Bullet>::const_iterator iter;
	std::vector<Bullet> bulletVec;
	Bullet bullet;
	int bulletCount;

	std::vector<Enemy>::const_iterator iter2;
	std::vector<Enemy> enemyVec;
	Enemy enemy;
	enemy.sprite.setTexture(enemyTex);
	enemyVec.push_back(enemy);
	int enemyCount;

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		bulletCount = 0;
		for (iter = bulletVec.begin(); iter != bulletVec.end(); iter++)
		{
			enemyCount = 0;
			for (iter2 = enemyVec.begin(); iter2 != enemyVec.end(); iter2++)
			{
				if (bulletVec[bulletCount].rect.getGlobalBounds().intersects(enemyVec[enemyCount].rect.getGlobalBounds()))
				{
					enemyVec[enemyCount].getHp()--;
					if (enemyVec[enemyCount].getHp() <= 0)
					{
						enemyVec[enemyCount].isAlive = false;
					}
				}

				enemyCount++;
			}

			bulletCount++;
		}

		enemyCount = 0;
		for (iter2 = enemyVec.begin(); iter2 != enemyVec.end(); iter2++)
		{
			if (enemyVec[enemyCount].isAlive == false)
			{
				enemyVec.erase(iter2);
				break;
			}

			enemyCount++;
		}

		//If we press space
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bullet.sprite.setTexture(bulletTex);
			//Set the position of the bullet to the position of the player
			bullet.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x / 2 - (32 / 5), (player.rect.getPosition().y + player.rect.getSize().y / 2));
			bullet.getDirection() = player.getDirection();
			//We sent it to our world
			bulletVec.push_back(bullet);
		}

		bulletCount = 0;
		//Draw our bullet to our world
		for (iter = bulletVec.begin(); iter != bulletVec.end(); iter++)
		{
			bulletVec[bulletCount].update();
			bulletVec[bulletCount].fire();
			window.draw(bulletVec[bulletCount].sprite);
			bulletCount++;
		}

		enemyCount = 0;
		//Draw our enemy to our world
		for (iter2 = enemyVec.begin(); iter2 != enemyVec.end(); iter2++)
		{
			enemyVec[enemyCount].update();
			enemyVec[enemyCount].move();
			window.draw(enemyVec[enemyCount].sprite);
			enemyCount++;
		}
		
		player.move();
		player.update();

		window.draw(text);
		window.draw(player.sprite);

		window.display();
	}

	return 0;
}