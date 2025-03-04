#include <SFML\Graphics.hpp>
#include "Screen.h"

bool Screen::isActive()
{
    return active;
}
bool Screen::set_activity_status(bool status)
{
    this->active = status;
    return true;
}

//game menu
GameMenuScreen::GameMenuScreen() {
    active = true;
    if (!menuTexture.loadFromFile("mainmenu.jpg")) {
        cout << "failed to load menu background" << endl;
    }

    if (!playButtonTexture.loadFromFile("play.png")) {
        cout << "failed to load play button" << endl;
    }

    if (!instructionsButtonTexture.loadFromFile("instructions.png")) {
        cout << "failed to load inst button" << endl;
    }

    menuBackground.setTexture(menuTexture);
    playButton.setTexture(playButtonTexture);
    instructionsButton.setTexture(instructionsButtonTexture);
    playButton.setPosition(820, 400);
    instructionsButton.setPosition(820, 300);
}

void GameMenuScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
int GameMenuScreen::getbuttonX() {
    return buttonX;
}
int GameMenuScreen::getbuttonY() {
    return buttonY;
}
int GameMenuScreen::getInsButtonX() {
    return insButtonX;
}
int GameMenuScreen::getInsButtonY() {
    return insButtonY;
}
int GameMenuScreen::getbuttonWidth() {
    return buttonWidth;
}
int GameMenuScreen::getbuttonHeight() {
    return buttonHeight;
}
void GameMenuScreen::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(menuBackground);
    window.draw(playButton);
    window.draw(instructionsButton);
    window.display();
}

// level selection
LevelSelectionScreen::LevelSelectionScreen()
{
    active = false;
    if (!backgroundTexture.loadFromFile("levelmenu.png")) {
        cout << "failed to load level background texture" << endl;
    }

    // Initialize level buttons
    for (int i = 0; i < 6; ++i) {
        // Set positions with gap between each button
        int x = 65 + i * 200; 
        int y = 520; 
        setPosition(i, x, y);
    }

    setLevelButton(0, "L1.png");
    setLevelButton(1, "L2.png");
    setLevelButton(2, "L3.png");
    setLevelButton(3, "L4.png");
    setLevelButton(4, "L5.png");
    setLevelButton(5, "L6.png");

    // select level
    if (!selectButtonTexture.loadFromFile("selectlevel.png")) {
        cout << "failed to load select button" << endl;
    }
    selectButton.setTexture(selectButtonTexture);
    selectButton.setPosition(440, 150);
    if (!backToHomeButtonTexture.loadFromFile("back.png")) {
        cout << "failed to load back button" << endl;
    }

    // back home button
    backToHomeButton.setTexture(backToHomeButtonTexture);
    backToHomeButton.setPosition(440, 70);

    backgroundSprite.setTexture(backgroundTexture);
}

// Set position for a specific level button
void LevelSelectionScreen::setPosition(int i, int x, int y) {
    levelButtons[i].setPosition(x, y);
}

// Set texture and sprite for a specific level button
void LevelSelectionScreen::setLevelButton(int index, const std::string& textureFile) {
    if (!levelButtonTextures[index].loadFromFile(textureFile)) {
        cout << "failed to load level button" << endl;
    }
    levelButtons[index].setTexture(levelButtonTextures[index]);
}

void LevelSelectionScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
int LevelSelectionScreen::getbuttonX() {
    return buttonX;
}
int LevelSelectionScreen::getbuttonY() {
    return buttonY;
}
int LevelSelectionScreen::getbuttonWidth() {
    return buttonWidth;
}
int LevelSelectionScreen::getbuttonHeight() {
    return buttonHeight;
}
void LevelSelectionScreen::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(backgroundSprite);

    // Draw level buttons
    for (int i = 0; i < 6; ++i) {
        window.draw(levelButtons[i]);
    }

    window.draw(selectButton);
    window.draw(backToHomeButton);

    window.display();
}
Sprite* LevelSelectionScreen::getlevelButtons() {
    return levelButtons;
}
void LevelSelectionScreen::setLevel(int l)
{
    this->levelNum = l;
}
int LevelSelectionScreen::getLevel()
{
    return this->levelNum;
}

// game window
GameWindowScreen::GameWindowScreen()
{
    active = false;
    makeGame = false;
}
void GameWindowScreen::constructLevel(int level, sf::RenderWindow& window)
{
    switch (level)
    {
    case 1:
    {
        if (!gameBackgroundTexture.loadFromFile("background.jpeg")) {
            cout << "failed to load game bg" << endl;
        }
        break;
    }
    case 4:
    {
        if (!gameBackgroundTexture.loadFromFile("nightbackground.jpg")) {
            cout << "failed to load night" << endl;
        }
        break;
    }
    case 5:
    {
        if (!gameBackgroundTexture.loadFromFile("nightbackground.jpg")) {
            cout << "failed to load night" << endl;
        }
        break;
    }
    case 6:
    {
        if (!gameBackgroundTexture.loadFromFile("roof.png")) {
            cout << "failed to load roof!" << endl;
        }
        break;
    }
    default:
    {
        if (!gameBackgroundTexture.loadFromFile("background.jpeg")) {
            cout << "failed to load bg" << endl;
        }
        break;
    }
    }
    gameBackgroundSprite.setTexture(gameBackgroundTexture);
    if (!makeGame)
    {
        game = new Game(level, window);
        makeGame = true;
    }
}

void GameWindowScreen::handleEvents(sf::RenderWindow& window) {
    // Handle events for the game window
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.mouseButton.button == sf::Mouse::Left) {
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;
            game->mouseClickFunctions(mouseX, mouseY, window);

        }
    }
}
void GameWindowScreen::mouseClick(int mouseX, int mouseY, sf::RenderWindow& window)
{
    game->mouseClickFunctions(mouseX, mouseY, window);
}
void GameWindowScreen::render(sf::RenderWindow& window) {
    // Render the game window
    window.clear();
    window.draw(gameBackgroundSprite);
    game->playGame(window);
    // Render other game elements as needed
    window.display();
}
int GameWindowScreen::getLives()
{
    return game->getLives();
}

//game over
GameOverScreen::GameOverScreen() {
    active = false;
    if (!gameOverTexture.loadFromFile("gameover.png")) {
        cout << "failed to load end" << endl;
    }

    if (!backToLevelsButtonTexture.loadFromFile("selectLevel.png")) {
        cout << "failed to load play" << endl;
    }
    if (!backToHomeButtonTexture.loadFromFile("back.png")) {
        cout << "failed to load back " << endl;
    }

    gameOverBackground.setTexture(gameOverTexture);

    backToLevel.setTexture(backToLevelsButtonTexture);
    backToLevel.setPosition(680, 510);

    backToHomeButton.setTexture(backToHomeButtonTexture);
    backToHomeButton.setPosition(300, 510);
}

void GameOverScreen::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
void GameOverScreen::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(gameOverBackground);
    window.draw(backToLevel);
    window.draw(backToHomeButton);
    window.display();
}

int GameOverScreen::getSelectLevelButtonX()
{
    return selectLevelButtonX;
}

int GameOverScreen::getSelectLevelButtonY()
{
    return selectLevelButtonY;
}

int GameOverScreen::getSelectLevelButtonWidth()
{
    return selectLevelButtonWidth;
}

int GameOverScreen::getSelectLevelButtonHeight()
{
    return selectLevelButtonHeight;
}

int GameOverScreen::getBackButtonX()
{
    return backButtonX;
}

int GameOverScreen::getBackButtonY()
{
    return backButtonY;
}

int GameOverScreen::getBackButtonWidth()
{
    return backButtonWidth;
}

int GameOverScreen::getBackButtonHeight()
{
    return backButtonHeight;
}


//instructions
InstructionsScreen::InstructionsScreen() {
    active = false;
    if (!instructionsBackgroundTexture.loadFromFile("instructionsbg.jpg")) {
        cout << "failed to load ins!" << endl;
    }

    if (!backToLevelsButtonTexture.loadFromFile("selectLevel.png")) {
        cerr << "failed to load play" << endl;
    }
    if (!backToHomeButtonTexture.loadFromFile("back.png")) {
        cerr << "failed to load back button" << endl;
    }

    instructionsBackground.setTexture(instructionsBackgroundTexture);

    backToLevel.setTexture(backToLevelsButtonTexture);
    backToLevel.setPosition(680, 510);

    backToHomeButton.setTexture(backToHomeButtonTexture);
    backToHomeButton.setPosition(300, 510);
}

void InstructionsScreen::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
void InstructionsScreen::render(sf::RenderWindow& window)
{
    window.clear();

    // Load font
    sf::Font font;
    if (!font.loadFromFile("Grovey.ttf")) {
        cout << "failed to load grovey" << endl;
    }

    sf::Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(35);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setPosition(350, 100);

    // Set instructions text
    instructionsText.setString(
        "  Welcome to Plants Vs. Zombies\n  (Insharah and Zara's Version)!\n"
        "To play, collect the Sun that falls\n from the sky and plant Plants\n to defend your home from incoming\n                      Zombies.\n"
        "TIP: Watch out for how many lives\n                 you have left.\n"
        "          \t   Enjoy the game!"
    );

    window.draw(instructionsBackground);
    window.draw(instructionsText);
    window.draw(backToLevel);
    window.draw(backToHomeButton);
    window.display();
}

int InstructionsScreen::getSelectLevelButtonX()
{
    return selectLevelButtonX;
}

int InstructionsScreen::getSelectLevelButtonY()
{
    return selectLevelButtonY;
}

int InstructionsScreen::getSelectLevelButtonWidth()
{
    return selectLevelButtonWidth;
}

int InstructionsScreen::getSelectLevelButtonHeight()
{
    return selectLevelButtonHeight;
}

int InstructionsScreen::getBackButtonX()
{
    return backButtonX;
}

int InstructionsScreen::getBackButtonY()
{
    return backButtonY;
}

int InstructionsScreen::getBackButtonWidth()
{
    return backButtonWidth;
}

int InstructionsScreen::getBackButtonHeight()
{
    return backButtonHeight;
}
