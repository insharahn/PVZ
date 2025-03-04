#include <SFML\Graphics.hpp>
#include "Game.h"

Game::Game() {}

void Game::initialize(int level, sf::RenderWindow& window)
{
	srand(time(nullptr)); //seed the random function

	levelNum = level;

	//initialize the zombie factory
	zombieFactory.initialize(level, window);
	zombieFactoryArray = zombieFactory.get_zombies_array();

	plantsArray = plantFactory.getPlantArray();

	plantPlaced = false; // flag for wehn plant has been placed
	plantingMode = false; // flag for when player is currently in planting mode
	cardSelectMode = false; //flag for card selection
	planted = false; //flag for decremeting the sun
	//plant coordinates initializtion
	plantX = 0;
	plantY = 0;

	sunCount = 0;
	sunCountSunflower = 0;
	totalSunCount = 0;

	sunSky.getProducingTimeClock().restart();
	sunSky.setProducingTime(3000);
	//sun that falls from the sky
	sunSky.x = 230 + rand() % (1010 - 230 + 1); //[230, 1010] range
	sunSky.y = 0;

	lawnmower = new Lawnmower[5]{ {window, 170, 200,1.0},{window, 170, 280,1.0},{window, 170, 360,2.0},{window, 170, 450,2.0},{window, 160, 550,2.0} };

	lives = 3;
}

Game::Game(int level, sf::RenderWindow& window)
{
	srand(time(nullptr)); //seed the random function

	levelNum = level;

	//initialize the zombie factory
	zombieFactory.initialize(level, window);
	zombieFactoryArray = zombieFactory.get_zombies_array();

	plantsArray = plantFactory.getPlantArray();

	plantPlaced = false; // flag for wehn plant has been placed
	plantingMode = false; // flag for when player is currently in planting mode
	cardSelectMode = false; //flag for card selection
	planted = false; //flag for decremeting the sun
	//plant coordinates initializtion
	plantX = 0;
	plantY = 0;

	sunCount = 0;
	sunCountSunflower = 0;
	totalSunCount = 0;

	sunSky.getProducingTimeClock().restart();
	sunSky.setProducingTime(3000);
	//sun that falls from the sky
	sunSky.x = 230 + rand() % (1010 - 230 + 1); //[230, 1010] range
	sunSky.y = 0;

	lawnmower = new Lawnmower[5]{ {window, 170, 200,1.0},{window, 170, 280,1.0},{window, 170, 360,2.0},{window, 170, 450,2.0},{window, 160, 550,2.0} };

	lives = 3;
}
void Game::setLives(int l)
{
	lives = l;
}
int Game::getLives()
{
	return lives;
}
int Game::getTotalSunCount()
{
	totalSunCount = sunCount + sunCountSunflower;
	return totalSunCount;
}
void Game::setTotalSunCount(int s)
{
	totalSunCount = s;
}
void Game::mouseClickFunctions(int mouseX, int mouseY, sf::RenderWindow& window)
{
	planted = false;

	if (inventory.cardSelected(mouseX, mouseY) && !cardSelectMode)
	{
		//cardSelected = true;
		plantingMode = true; // enter planting mode when a card is selected
		cardSelectMode = true;
	}
	else if (plantingMode && !plantPlaced && cardSelectMode) // check if in planting mode and no plant has been placed yet
	{
		if (totalSunCount >= plantFactory.getCost(inventory.getType())) //only plant if enough sun
		{
			plantX = (float)mouseX;
			plantY = (float)mouseY;
			if (plantFactory.plantPlaced(plantX, plantY)) //if a plant is clicked within the range
			{
				plantFactory.addPlants(plantX, plantY, inventory.getType(), window);
				plantPlaced = false; // set flag to false so another plant can be placed
				plantingMode = true;
				cardSelectMode = false; //set card select mode to false so only one plant can be placed at a time after selecting a card
				planted = true;
				totalSunCount -= plantFactory.getCost(inventory.getType()); //subtract the cost of the plant
				cout << "sun count: " << totalSunCount << endl;

			}
		}
	}
	if (sunSky.gotCollected(mouseX, mouseY))
	{
		sunSky.setExists(false);
		sunCount += 25; //increment the count of the sun when collected
	}
}

void Game::playGame(sf::RenderWindow& window)
{
	//handle inventory
	inventory.setLevelNum(levelNum);
	inventory.drawInventory(window);
	inventory.drawSelector(window);

	//handle zombies
	zombieFactory.moveallzombies(window);


	// loop through all plants
	for (int i = 0; i < plantFactory.getPlantIndex(); i++)
	{
		// draw the plant
		if (plantsArray[i]->getIsAlive())
		{
			plantsArray[i]->draw(window);
			plantsArray[i]->action(window);
		}

		//store the count of the sun produced by the sunflower
		sunCountSunflower = plantsArray[i]->getSunCount();
	}



	if (sunSky.getProducingTimeClock().getElapsedTime().asMilliseconds() >= sunSky.getProducingTime())
	{
		//draw the sun sprite
		//load the texture of the sun
		sf::Texture sunTexture;
		sunTexture.loadFromFile("sun.png");
		sunSky.getSprite().setTexture(sunTexture);
		//draw the sun
		//if (sunSky.getExists())
		window.draw(sunSky.getSprite());
		sunSky.moveSun();

		if (!sunSky.getExists())
		{
			sunSky.y = 0;
			sunSky.x = 230 + (rand() % (1010 - 230 + 1));
			sunSky.setExists(true);
			sunSky.getProducingTimeClock().restart();
		}
	}
	//draw the lawnomower
	for (int i = 0; i < 5; i++) {
		lawnmower[i].draw(window);

	}
	//collision w zombies
	for (int i = 0; i < 5; i++) {
		if (lawnmower[i].checkCollision(lawnmower, zombieFactoryArray, window, zombieFactory.get_totalzombies()))
		{
			lawnmower[i].move(window);
		}
	}

	if (zombieFactory.reachedHouse()) //decrement lives upon reaching the house
		lives--;

	//collisions
	zombieFactory.checkPeaZombieCollision(zombieFactoryArray, plantsArray, plantFactory.getPlantIndex());
	zombieFactory.checkPlantZombieCollision(zombieFactoryArray, plantsArray, plantFactory.getPlantIndex());

	//load the font for output
	sf::Font font;
	if (!font.loadFromFile("ARCADECLASSIC.TTF"))
	{
		//font loading failure
		cout << "failed to load arcadeclassic" << endl;
	}

	//output
	//outputting lives
	sf::Text totaLivesText;
	totaLivesText.setFont(font);
	totaLivesText.setCharacterSize(25);
	totaLivesText.setStyle(sf::Text::Bold);
	totaLivesText.setFillColor(sf::Color::White);
	totaLivesText.setPosition(1100, 8);
	totaLivesText.setString("LIVES  " + std::to_string(lives));

	//outputting the sun count
	sf::Text totalSunCountText;
	totalSunCountText.setFont(font);
	totalSunCountText.setCharacterSize(25);
	totalSunCountText.setStyle(sf::Text::Bold);
	totalSunCountText.setFillColor(sf::Color::White);
	totalSunCountText.setPosition(180, 8);

	getTotalSunCount();
	if (planted) //subtract the planted plant's cost
		totalSunCount -= plantFactory.getCost(inventory.getType());
	totalSunCountText.setString(std::to_string(totalSunCount) + "\nTOTAL SUN");

	//draw the text objects
	window.draw(totaLivesText);
	window.draw(totalSunCountText);
}

Game::~Game()
{
	delete[] lawnmower;
}
