#include <SFML\Graphics.hpp>
#include "Pea.h"

Pea::Pea()
{
    this->x = 0;
    this->y = 0;
}
void Pea::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}
void Pea::setExists(bool exists)
{
    this->exists = exists;
}
bool Pea::getExists()
{
    return this->exists;
}
// getter for sprite
Sprite& Pea::getSprite()
{
    return sprite;
}
//damage
void Pea::setDamage(float damage)
{
    this->damage = damage;
}
float Pea::getDamage()
{
    return this->damage;
}
//function to determine whether pea is still on the screen
void Pea::peaExists()
{
    if (this->x < 1200)
        setExists(true);
    else
        setExists(false);
}
//move the pea
void Pea::updatePosition(float speed)
{
    this->x += speed;
    this->sprite.setPosition(x, y);

    if (x > 1200) //reached edge of screen
    {
        exists = false;
    }
}

