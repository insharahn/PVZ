#include <SFML\Graphics.hpp>
#include "Lawnmower.h"

Lawnmower::Lawnmower(RenderWindow& window, float X, float Y, float Speed) {


	lawn_texture.loadFromFile("lawnmower.png");
	lawn_sprite.setTexture(lawn_texture);
	lawn_sprite.setPosition(X, Y);
	speed = Speed;
	setposition(X, Y);
	window.draw(lawn_sprite);

}
void Lawnmower::draw(RenderWindow& window) {

	lawn_texture.loadFromFile("lawnmower.png");
	lawn_sprite.setTexture(lawn_texture);
	lawn_sprite.setPosition(x, y);
	window.draw(lawn_sprite);
}
void Lawnmower::move(RenderWindow& window) {
	if (activated == true) {

		lawn_texture.loadFromFile("movinglawn.png");
		lawn_sprite.setTexture(lawn_texture);
		lawn_sprite.setTextureRect(IntRect(0, 0, 70.588, 70));
		this->x += speed;
		this->lawn_sprite.setPosition(x, y);
		animate(window, 70.588, 70, 17);

		window.draw(lawn_sprite);
	}
}
void Lawnmower::animate(RenderWindow& window, float frameWidth, float frameHeight, int numFrames) {
	if (clock.getElapsedTime().asSeconds() >= 0.05f) {
		currentFrame = (currentFrame + 1) % numFrames;
		// Calculate the rectangle for the current frame

		lawn_sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
		clock.restart(); // Restart the clock
		//cout << "Animating";
	}
}

bool Lawnmower::checkCollision(Lawnmower* l, Zombie** z, RenderWindow& window, int totalZombies) {
	int i = 0;
	l[i].activated = false; // Initialize collision detection variable to false
	for (i = 0; i < 5; i++) { // Loop through each lawnmower
		//cout << "checking lawnmoer " << i << endl;
		for (int j = 0; j < totalZombies; j++) { // Loop through each zombie
			if ((l[i].getx() <= z[j]->getpositionx() + 90) &&
				(l[i].getx() >= z[j]->getpositionx()) &&
				(l[i].gety() <= z[j]->getpositiony() + 120) &&
				(l[i].gety() >= z[j]->getpositiony())) {

				z[j]->kill(); //kill the run over zombie

				l[i].activated = true; // Set collisionDetected to true

				break; // Exit the inner loop since collision is detected with one lawnmower
			}
		}
		if (l[i].activated) // If collision detected, exit the outer loop too
		{
			break;
		}
	}
	// Check if collision was detected and return accordingly
	return activated;
}



void Lawnmower::setposition(float X, float Y) {
	this->x = X;
	this->y = Y;
}
float Lawnmower::getx() {
	return this->x;
}
float Lawnmower::gety() {
	return this->y;
}
float Lawnmower::getwidth() {
	return lawn_sprite.getTexture()->getSize().x;
}
float Lawnmower::getheight() {
	return lawn_sprite.getTexture()->getSize().y;
}