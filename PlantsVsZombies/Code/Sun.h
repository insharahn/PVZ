#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "coordinates.h"

using namespace std;
using namespace sf;

class Sun : public coordinates
{
private:
	sf::Sprite sprite;
	int speed;
	int producingTime;
	bool exists;
	bool wasCollected;
	sf::Clock producingTimeClock;
public:
	Sun();

	//setters
	void setSpeed(int s);
	void setProducingTime(int t);
	void setExists(bool e);
	void setWasSunCollected(bool s);

	//getters
	sf::Sprite& getSprite();
	int getSpeed();
	int getProducingTime();
	sf::Clock& getProducingTimeClock();
	bool getExists();
	bool getWasSunCollected(); //a function for if sun disappears because it was collected

	//member functions
	//function to move the sun down
	void moveSun();
	//function for collection
	bool gotCollected(int mouseX, int mouseY);
};