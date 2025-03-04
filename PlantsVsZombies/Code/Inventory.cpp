#include <SFML\Graphics.hpp>
#include "Inventory.h"

Inventory::Inventory() {}

Inventory::Inventory(int levelNum, sf::RenderWindow& window)
{
	type = 0; //let there only be 1 type for now
	this->levelNum = levelNum;
	switch (levelNum)
	{
	case 1: //sunflowers and peashooters available
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);

		break;
	}
	case 2: //sunflowers, peashooters, wallnuts available
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(wallnutCard);
		break;
	}
	case 3: //sunflowers, peashooters, wallnuts, cherrybombs
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(wallnutCard);
		window.draw(cherrybombCard);

		break;
	}
	case 4: //all
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		break;
	}
	case 5: //all
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		break;
		break;
	}
	case 6: // all + fumeshroom
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 10);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		sf::Texture fumeshroomTexture;
		if (!fumeshroomTexture.loadFromFile("fumeshroomCard.png"))
			cout << "FumeshroomCard not loaded." << endl;
		fumeshroomCard.setTexture(fumeshroomTexture);
		fumeshroomCard.setPosition(0, 469);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		window.draw(fumeshroomCard);
		break;
	}
	default:
		break;
	}
}
//setters
void Inventory::setLevelNum(int l) { this->levelNum = l; }
void Inventory::setType(int t) { this->type = t; }
//getters
int Inventory::getLevelNum() { return this->levelNum; }
int Inventory::getType() { return this->type; }
Sprite& Inventory::getSelectorSprite() { return this->selector; }
//function to determine if a card is selected and also set the type of the card selected
bool Inventory::cardSelected(int mouseX, int mouseY)
{

	//cards are all roughly 106x68

	//clicked the peashooter
	if (mouseX >= 0 && mouseX <= 106 && mouseY >= 67 && mouseY <= 134)
	{
		cout << "card was selected" << endl;
		type = 1;
		return true;
	}
	//clicked the sunflower
	if (mouseX >= 0 && mouseX <= 106 && mouseY >= 134 && mouseY <= 201)
	{
		cout << "card was selected" << endl;
		type = 2;
		return true;
	}
	//clicked the wallnut: rewarded after level 1
	if (levelNum > 1 && mouseX >= 0 && mouseX <= 106 && mouseY >= 201 && mouseY <= 268)
	{
		cout << "card was selected" << endl;
		type = 3;
		return true;
	}
	//clicked the cherrybomb: rewarded after level 2
	if (levelNum > 2 && mouseX >= 0 && mouseX <= 106 && mouseY >= 268 && mouseY <= 335)
	{
		cout << "card was selected" << endl;
		type = 4;
		return true;
	}
	//clicked the snowpea: rewarded after level 3
	if (levelNum > 3 && mouseX >= 0 && mouseX <= 106 && mouseY >= 335 && mouseY <= 402)
	{
		type = 5;
		return true;
	}
	//clicked the repeater: rewareded after level 3
	if (levelNum > 3 && mouseX >= 0 && mouseX <= 106 && mouseY >= 402 && mouseY <= 469)
	{
		cout << "card was selected" << endl;
		type = 6;
		return true;
	}
	//clicked the fumeshroom: rewareded after level 5
	if (levelNum > 3 && mouseX >= 0 && mouseX <= 106 && mouseY >= 469 && mouseY <= 536)
	{
		cout << "card was selected" << endl;
		type = 7;
		return true;
	}
	else
		return false;

}
void Inventory::drawSelector(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("selectedCardBorder.png"))
		cout << "Selector not loaded." << endl;
	selector.setTexture(texture);
	switch (type)
	{
	case 1: //peashooter
	{
		selector.setPosition(-5, 62);
		window.draw(selector);
		break;
	}
	case 2: //sunflower
	{
		selector.setPosition(-5, 130);
		window.draw(selector);
		break;
	}
	case 3: //wallnut
	{
		selector.setPosition(-5, 200);
		window.draw(selector);
		break;
	}
	case 4: //cherrybomb
	{
		selector.setPosition(-5, 265);
		window.draw(selector);
		break;
	}
	case 5: //snowpea
	{
		selector.setPosition(-5, 330);
		window.draw(selector);
		break;
	}
	case 6: //repeater
	{
		selector.setPosition(-5, 395);
		window.draw(selector);
		break;
	}
	case 7: //fumeshroom
	{
		selector.setPosition(-5, 465);
		window.draw(selector);
		break;
	}
	default:
		break;
	}

}
void Inventory::drawInventory(sf::RenderWindow& window)
{
	switch (levelNum)
	{
	case 1: //sunflowers and peashooters available
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);

		break;
	}
	case 2: //sunflowers, peashooters, wallnuts available
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(wallnutCard);
		break;
	}
	case 3: //sunflowers, peashooters, wallnuts, cherrybombs
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(wallnutCard);
		window.draw(cherrybombCard);

		break;
	}
	case 4: //all
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		break;
	}
	case 5: //all
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		break;
		break;
	}
	case 6: // all + fumeshroom
	{
		sf::Texture sunCounterTexture;
		if (!sunCounterTexture.loadFromFile("suncounter.png"))
			cout << "Sun counter not loaded." << endl;
		sunCounter.setTexture(sunCounterTexture);
		sunCounter.setPosition(100, 15);

		sf::Texture peashooterTexture;
		if (!peashooterTexture.loadFromFile("peashooterCard.png"))
			cout << "PeashooterCard not loaded." << endl;
		peashooterCard.setTexture(peashooterTexture);
		peashooterCard.setPosition(0, 67);

		sf::Texture sunflowerTexture;
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png"))
			cout << "SunflowerCard not loaded." << endl;
		sunflowerCard.setTexture(sunflowerTexture);
		sunflowerCard.setPosition(0, 134);

		sf::Texture wallnutTexture;
		if (!wallnutTexture.loadFromFile("wallnutCard.png"))
			cout << "WallnutCard not loaded." << endl;
		wallnutCard.setTexture(wallnutTexture);
		wallnutCard.setPosition(0, 201);

		sf::Texture cherrybombTexture;
		if (!cherrybombTexture.loadFromFile("cherrybombCard.png"))
			cout << "CherrybombCard not loaded." << endl;
		cherrybombCard.setTexture(cherrybombTexture);
		cherrybombCard.setPosition(0, 268);

		sf::Texture snowpeaTexture;
		if (!snowpeaTexture.loadFromFile("snowpeaCard.png"))
			cout << "SnowpeaCard not loaded." << endl;
		snowpeaCard.setTexture(snowpeaTexture);
		snowpeaCard.setPosition(0, 335);

		sf::Texture repeaterTexture;
		if (!repeaterTexture.loadFromFile("repeaterCard.png"))
			cout << "RepeaterCard not loaded." << endl;
		repeaterCard.setTexture(repeaterTexture);
		repeaterCard.setPosition(0, 402);

		sf::Texture fumeshroomTexture;
		if (!fumeshroomTexture.loadFromFile("fumeshroomCard.png"))
			cout << "FumeshroomCard not loaded." << endl;
		fumeshroomCard.setTexture(fumeshroomTexture);
		fumeshroomCard.setPosition(0, 469);

		window.draw(sunCounter);
		window.draw(peashooterCard);
		window.draw(sunflowerCard);
		window.draw(cherrybombCard);
		window.draw(wallnutCard);
		window.draw(snowpeaCard);
		window.draw(repeaterCard);
		window.draw(fumeshroomCard);
		break;
	}
	default:
		break;
	}
}

Inventory::~Inventory() {}