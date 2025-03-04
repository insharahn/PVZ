#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class Screen 
{
public:
    bool active;
    int levelNum;
    virtual void handleEvents(sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    bool isActive();
    bool set_activity_status(bool status);
};

class GameMenuScreen : public Screen {
private:
    sf::Texture menuTexture;
    sf::Texture playButtonTexture;
    sf::Texture instructionsButtonTexture;
    sf::Sprite menuBackground;
    sf::Sprite playButton;
    sf::Sprite instructionsButton;
    int buttonX = 820; 
    int buttonY = 400; 
    int buttonWidth = 306; 
    int buttonHeight = 133; 
    int insButtonX = 820;
    int insButtonY = 300;
public:
    GameMenuScreen();
    void handleEvents(sf::RenderWindow& window);
    int getbuttonX();
    int getbuttonY();
    int getInsButtonX();
    int getInsButtonY();
    int getbuttonWidth();
    int getbuttonHeight();
    void render(sf::RenderWindow& window);
};

class LevelSelectionScreen : public Screen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture levelButtonTextures[6];
    sf::Sprite levelButtons[6];
    sf::Texture selectButtonTexture;
    sf::Sprite selectButton;
    sf::Texture backToHomeButtonTexture;
    sf::Sprite backToHomeButton;
    int buttonX = 440;
    int buttonY = 70;
    int buttonWidth = 306;
    int buttonHeight = 134;
public:

    LevelSelectionScreen();
    // Set position for a specific level button
    void setPosition(int i, int x, int y);
    // Set texture and sprite for a specific level button
    void setLevelButton(int index, const std::string& textureFile);
    void handleEvents(sf::RenderWindow& window);
    int getbuttonX();
    int getbuttonY();
    int getbuttonWidth();
    int getbuttonHeight();
    void render(sf::RenderWindow& window);
    Sprite* getlevelButtons();
    void setLevel(int l);
    int getLevel();
};

class GameWindowScreen : public Screen {
private:
    sf::Texture gameBackgroundTexture;
    sf::Sprite gameBackgroundSprite;
    Game *game;
    bool makeGame;
public:
    GameWindowScreen();
    void constructLevel(int level, sf::RenderWindow& window);
    void handleEvents(sf::RenderWindow& window);
    void mouseClick(int mouseX, int mouseY, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    int getLives();
};


class GameOverScreen : public Screen {
private:
    sf::Texture gameOverTexture;
    sf::Texture backToHomeButtonTexture;
    sf::Texture backToLevelsButtonTexture;
    sf::Sprite gameOverBackground;
    sf::Sprite backToHomeButton;
    sf::Sprite backToLevel;
    int selectLevelButtonX = 680;
    int selectLevelButtonY = 510;
    int backButtonX = 300;
    int backButtonY = 510;
    int selectLevelButtonWidth = 306; 
    int selectLevelButtonHeight = 133;
    int backButtonWidth = 306;
    int backButtonHeight = 134;
public:
    GameOverScreen();
    void handleEvents(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    int getSelectLevelButtonX();

    int getSelectLevelButtonY();

    int getSelectLevelButtonWidth();
    int getSelectLevelButtonHeight();

    int getBackButtonX();
    int getBackButtonY();

    int getBackButtonWidth();

    int getBackButtonHeight();
};

class InstructionsScreen : public Screen {
private:
    sf::Texture instructionsBackgroundTexture;
    sf::Texture backToHomeButtonTexture;
    sf::Texture backToLevelsButtonTexture;
    sf::Sprite instructionsBackground;
    sf::Sprite backToHomeButton;
    sf::Sprite backToLevel;
    int selectLevelButtonX = 680;
    int selectLevelButtonY = 510;
    int backButtonX = 300;
    int backButtonY = 510;
    int selectLevelButtonWidth = 306;
    int selectLevelButtonHeight = 133;
    int backButtonWidth = 306;
    int backButtonHeight = 134;
public:
    InstructionsScreen();
    void handleEvents(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    int getSelectLevelButtonX();
    int getSelectLevelButtonY();
    int getSelectLevelButtonWidth();
    int getSelectLevelButtonHeight();
    int getBackButtonX();
    int getBackButtonY();
    int getBackButtonWidth();
    int getBackButtonHeight();

};