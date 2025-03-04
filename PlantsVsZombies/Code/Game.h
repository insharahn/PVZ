#pragma once
#include <ctime>

#include "Plant.h"
#include "Inventory.h"
#include "Sun.h"
#include "Lawnmower.h"
#include "MouseInput.h"

class Game
{
private:
	PlantFactory plantFactory;
	Plant** plantsArray; //so thats its easier to access the memebrs

	Lawnmower* lawnmower;

	Inventory inventory;

	Sun sunSky;

	ZombieFactory zombieFactory;
	Zombie** zombieFactoryArray; //so thats its easier to access the members

	//flags for the plant placement logic
	bool plantPlaced;
	bool plantingMode;
	bool cardSelectMode;
	bool planted;

	//plant coordinates determined upon mouseclick
	float plantX;
	float plantY;

	int levelNum;

	int sunCount;
	int sunCountSunflower;
	int totalSunCount;

	int lives;

public:
	Game();
	void initialize(int level, sf::RenderWindow& window);
	Game(int level, sf::RenderWindow& window);
	void setLives(int l);
	int getLives();
	int getTotalSunCount();
	void setTotalSunCount(int s);
	void mouseClickFunctions(int mouseX, int mouseY, sf::RenderWindow& window);

	void playGame(sf::RenderWindow& window);
	virtual ~Game();
};

