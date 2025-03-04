#pragma once
#include <iostream>
#include <SFML/Graphics.hpp> // SFML library for loading sprites
#include"coordinates.h"
#include"Zombie.h"

using namespace std;
using namespace sf;
class Lawnmower :public coordinates {
private:

private:
	sf::Clock clock; // Clock for controlling animation frame change
	//float frameDuration = 0.025f; // Duration between frame changes in seconds
	int currentFrame = 0; // Current frame index
	int numFrames = 13; // Total number of frames in the animation
	Sprite lawn_sprite;
	float speed;
	Texture lawn_texture;
	bool activated = false;
public:
	Lawnmower(RenderWindow& window, float X, float Y, float Speed);
	void draw(RenderWindow& window);
	void move(RenderWindow& window);
	void animate(RenderWindow& window, float frameWidth, float frameHeight, int numFrames);
	bool checkCollision(Lawnmower* l, Zombie** z, RenderWindow& window, int totalZombies);
	void setposition(float X, float Y);
	float getx();
	float gety();
	float getwidth();
	float getheight();
};