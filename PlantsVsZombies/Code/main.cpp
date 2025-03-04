/*OOP FINAL PROJECT
		INSHARAH IRFAN NAZIR 23I-0615
				ZARA NOOR QAZI 23I-0681
								   CS-D*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>

#include "Screen.h"

using namespace sf;
using namespace std;

//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("background.jpg");

	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1280, 720), "Plants Vs Zombies (Zara and Insharah's Version)");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;

	Clock clock;

	GameMenuScreen gameMenuScreen;
	LevelSelectionScreen levelselection;
	GameWindowScreen gameWindow;
	GameOverScreen gameOverScreen;
	InstructionsScreen instructionsScreen;
	

		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			float moneyTime = timeMoney.getElapsedTime().asSeconds();

			clock.restart();
			time = time / 800;

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();

				if (gameMenuScreen.isActive()) {
					gameMenuScreen.handleEvents(window);
					gameMenuScreen.render(window);
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							int mouseX = sf::Mouse::getPosition(window).x;
							int mouseY = sf::Mouse::getPosition(window).y;

							//play button to levels
							if (mouseX >= gameMenuScreen.getbuttonX() && mouseX <= gameMenuScreen.getbuttonX() + gameMenuScreen.getbuttonWidth() &&
								mouseY >= gameMenuScreen.getbuttonY() && mouseY <= gameMenuScreen.getbuttonY() + gameMenuScreen.getbuttonHeight()) {
								gameMenuScreen.set_activity_status(false);
								levelselection.set_activity_status(true);
							}
							//instructions button to instructions
							if (mouseX >= gameMenuScreen.getInsButtonX() && mouseX <= gameMenuScreen.getInsButtonX() + gameMenuScreen.getbuttonWidth() &&
								mouseY >= gameMenuScreen.getInsButtonY() && mouseY <= gameMenuScreen.getInsButtonY() + gameMenuScreen.getbuttonHeight()) {
								gameMenuScreen.set_activity_status(false);
								instructionsScreen.set_activity_status(true);
							}
						}
					}


				}
				else if (levelselection.isActive()) {
					cout << "Level ";
					levelselection.handleEvents(window);
					levelselection.render(window);
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							int mouseX = sf::Mouse::getPosition(window).x;
							int mouseY = sf::Mouse::getPosition(window).y;

							//back home button
							if (mouseX >= levelselection.getbuttonX() && mouseX <= levelselection.getbuttonX() + levelselection.getbuttonWidth() &&
								mouseY >= levelselection.getbuttonY() && mouseY <= levelselection.getbuttonY() + levelselection.getbuttonHeight()) {
								levelselection.set_activity_status(false);
								gameMenuScreen.set_activity_status(true);
							}
							// Check if any level button is clicked
							for (int i = 0; i < 6; ++i) {
								if (mouseX >= levelselection.getlevelButtons()[i].getPosition().x && mouseX <= levelselection.getlevelButtons()[i].getPosition().x + levelselection.getlevelButtons()[i].getGlobalBounds().width &&
									mouseY >= levelselection.getlevelButtons()[i].getPosition().y && mouseY <= levelselection.getlevelButtons()[i].getPosition().y + levelselection.getlevelButtons()[i].getGlobalBounds().height) {
									cout << "Level " << i + 1 << " selected" << endl;
									levelselection.set_activity_status(false);
									gameWindow.set_activity_status(true);
									levelselection.setLevel(i + 1);
								}
							}
						}
					}


				}
				else if (gameWindow.isActive())
				{

					gameWindow.constructLevel(levelselection.getLevel(), window);
					gameWindow.handleEvents(window);
					gameWindow.render(window);
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							int mouseX = sf::Mouse::getPosition(window).x;
							int mouseY = sf::Mouse::getPosition(window).y;
							gameWindow.mouseClick(mouseX, mouseY, window);
						}
					}
					if (gameWindow.getLives() < 1) //lives fell to 0 = lost the game
					{
						gameWindow.set_activity_status(false);
						gameOverScreen.set_activity_status(true);
					}
				}
				else if (gameOverScreen.isActive())
				{
					gameOverScreen.render(window);
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							int mouseX = sf::Mouse::getPosition(window).x;
							int mouseY = sf::Mouse::getPosition(window).y;

							//levels
							if (mouseX >= gameOverScreen.getSelectLevelButtonX() && mouseX <= gameOverScreen.getSelectLevelButtonX() + gameOverScreen.getSelectLevelButtonWidth()
								&& mouseY >= gameOverScreen.getSelectLevelButtonY() && mouseY <= gameOverScreen.getSelectLevelButtonY() + gameOverScreen.getSelectLevelButtonHeight())
							{
								gameOverScreen.set_activity_status(false);
								levelselection.set_activity_status(true);
							}
							//back to home aka game menu
							else if (mouseX >= gameOverScreen.getBackButtonX() && mouseX <= gameOverScreen.getBackButtonX() + gameOverScreen.getBackButtonWidth()
								&& mouseY >= gameOverScreen.getBackButtonY() && mouseY <= gameOverScreen.getBackButtonY() + gameOverScreen.getBackButtonHeight())
							{
								gameOverScreen.set_activity_status(false);
								gameMenuScreen.set_activity_status(true);
							}
						}
					}
				}
				else if (instructionsScreen.isActive())
				{
					instructionsScreen.render(window);
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							int mouseX = sf::Mouse::getPosition(window).x;
							int mouseY = sf::Mouse::getPosition(window).y;

							//levels
							if (mouseX >= instructionsScreen.getSelectLevelButtonX() && mouseX <= instructionsScreen.getSelectLevelButtonX() + instructionsScreen.getSelectLevelButtonWidth()
								&& mouseY >= instructionsScreen.getSelectLevelButtonY() && mouseY <= instructionsScreen.getSelectLevelButtonY() + instructionsScreen.getSelectLevelButtonHeight())
							{
								instructionsScreen.set_activity_status(false);
								levelselection.set_activity_status(true);
							}
							//back to home aka game menu
							else if (mouseX >= instructionsScreen.getBackButtonX() && mouseX <= instructionsScreen.getBackButtonX() + instructionsScreen.getBackButtonWidth()
								&& mouseY >= instructionsScreen.getBackButtonY() && mouseY <= instructionsScreen.getBackButtonY() + instructionsScreen.getBackButtonHeight())
							{
								instructionsScreen.set_activity_status(false);
								gameMenuScreen.set_activity_status(true);
							}
						}
					}
				}

			}

			//Create a background
			createBack(window);

			window.setSize(sf::Vector2u(1280, 720));
			//window.setSize(sf::Vector2u(1100, 680));

		}
	return 0;
}
