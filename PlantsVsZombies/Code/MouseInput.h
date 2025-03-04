#pragma once
#include <iostream>
#include "Sun.h"

using namespace sf;
using namespace std;

class MouseInput
{
private:
    sf::RenderWindow& window;
    Sun* sun;
public:
    MouseInput(sf::RenderWindow& window, Sun* sun);

    void handleInput(sf::RenderWindow& window);

    virtual ~MouseInput();

private: //encapsulate
    void handleMouseClick(sf::Event::MouseButtonEvent& mouseButton);
};
