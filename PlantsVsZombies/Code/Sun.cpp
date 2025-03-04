#include <iostream>
#include "Sun.h"
using namespace std;
using namespace sf;

Sun::Sun()
{
	x = 0;
	y = 0;
	speed = 3;
	producingTime = 10000; //10 seconds
	exists = true; //start off with true so that we can set it to false once its collected or it disappears
	wasCollected = false; //set the flag to false until it gets collected
	producingTimeClock.restart();
}

//setters
void Sun::setSpeed(int s) { this->speed = s; }
void Sun::setProducingTime(int t) { this->producingTime = t; }
void Sun::setExists(bool e) { this->exists = e; }
void Sun::setWasSunCollected(bool s) { this->wasCollected = s; }
//getters
sf::Sprite& Sun::getSprite() { return this->sprite; }
int Sun::getSpeed() { return this->speed; }
int Sun::getProducingTime() { return this->producingTime; }
sf::Clock& Sun::getProducingTimeClock() { return this->producingTimeClock; }
bool Sun::getExists() { return this->exists; }
bool Sun::getWasSunCollected() { return this->wasCollected; } //a function for is fun disappears because it was collected
//member functions
//function to move the sun down
void Sun::moveSun()
{

	y += 1; //move 1 pixel at a time
	sprite.setPosition(x, y);

	if (y > 625) //reaches the bottom edge of the lawn, should now be unclickable
		exists = false;
}

bool Sun::gotCollected(int mouseX, int mouseY)
{
	if (mouseX >= x && mouseX <= x + 60 && mouseY >= y && mouseY <= y + 60) // check if mouse is within the sun sprite png based on the 60x60 size
	{
		setWasSunCollected(true);
		return true;
	}
	else
	{
		setWasSunCollected(false);
		return false;
	}
}
