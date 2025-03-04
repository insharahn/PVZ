#include <SFML\Graphics.hpp>
#include "MouseInput.h"

MouseInput::MouseInput(sf::RenderWindow& window, Sun* sun) : window(window), sun(sun) {}

void MouseInput::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            handleMouseClick(event.mouseButton);
        }
    }
}

MouseInput::~MouseInput()
{
    delete sun;
}

//encapsulate
void MouseInput::handleMouseClick(sf::Event::MouseButtonEvent& mouseButton)
{
    int mouseX = mouseButton.x;
    int mouseY = mouseButton.y;

    //if sun is clicked
    if (sun && sun->gotCollected(mouseX, mouseY))
    {
        //set its existence to false
        sun->setExists(false);
    }
}