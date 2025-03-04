#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Inventory
{
private:
	sf::Sprite peashooterCard;
	sf::Sprite sunflowerCard;
	sf::Sprite repeaterCard;
	sf::Sprite wallnutCard;
	sf::Sprite snowpeaCard;
	sf::Sprite cherrybombCard;
	sf::Sprite fumeshroomCard;
	sf::Sprite selector;
	sf::Sprite sunCounter;
	int type;
	int levelNum;
public:
	Inventory();
	Inventory(int levelNum, sf::RenderWindow& window);
	//setters
	void setLevelNum(int l);
	void setType(int t);
	//getters
	int getLevelNum();
	int getType();
	Sprite& getSelectorSprite();
	//function to determine if a card is selected and also set the type of the card selected
	bool cardSelected(int mouseX, int mouseY);
	void drawSelector(sf::RenderWindow& window);
	void drawInventory(sf::RenderWindow& window);
	virtual ~Inventory();

};

