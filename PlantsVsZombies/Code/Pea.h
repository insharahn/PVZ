#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "coordinates.h"
using namespace std;
using namespace sf;

//the class for the projectile pea
class Pea : public coordinates
{
private:
    sf::Sprite sprite;  // sprite for rendering
    float damage;
    bool exists; //flag for existence which will determine when to shoot the next pea
public:
    Pea();
    void setPosition(float x, float y);
    void setExists(bool exists);
    bool getExists();
    // getter for sprite
    Sprite& getSprite();
    //damage
    void setDamage(float damage);
    float getDamage();
    //function to determine whether pea is still on the screen
    void peaExists();
    //move the pea
    void updatePosition(float speed);
};

