#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Pea.h"
#include "coordinates.h"
#include "Sun.h"
#include "MouseInput.h"

using namespace std;
using namespace sf;

class Plant : public coordinates
{
protected:
    sf::Sprite sprite;  // sprite for rendering
    int type; //number the plants to keep track of them
    int cost;  // price of plant
    float health;  // plant's health points
    bool isAlive;  // flag to indicate if the plant is alive
    static int sunCount; //keeps track of the counted sun, static int so it can be initialized just once and retain its value
    int numberOfPeas; //how many peas a plant shoots
    bool exploded; //flag for explosion of cherrybomb
    Pea *pea; //array of peas keeping in mind the max amount

public:
    Plant();

    Plant(int cost, float health);

    virtual ~Plant();

    //setters
    void setCost(int cost);
    void setHealth(float health);
    void setAliveStatus(bool alive);
    void setNumberOfPeas(int peas);
    void setExploded(bool e);
    void setPosition(float x, float y);
    // getters
    int getCost() const;
    float getHealth() const;
    bool getIsAlive() const;
    int getNumberOfPeas() const;
    Pea* getPea() const;
    Sprite& getSprite();
    int getType() const;
    void takeDamage(float damage);
    int getSunCount();
    bool getExploded();

    // draw the sprite, to be different for every type of plant
    virtual void draw(sf::RenderWindow& window) = 0;

    //for actions i.e. shoot, produce sun, explode, roll, etc
    virtual void action(sf::RenderWindow& window) = 0;
};

class ShooterPlant : public Plant
{
protected: //protected so that child classes can modify these values easily
    float speed; //speed of peas
public:
    ShooterPlant();

    void setSpeed(float speed);

    float getSpeed() const;

};

class Peashooter : public ShooterPlant
{
public:
    Peashooter();
    Peashooter(sf::RenderWindow& window, float x, float y);
    void setPosition(float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    //define the pure virtual function to shoot the peas
    virtual void action(sf::RenderWindow& window);
    virtual ~Peashooter();
};

class Repeater : public ShooterPlant
{
public:
    Repeater();
    Repeater(sf::RenderWindow& window, float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    //define the pure virtual function to shoot the peas
    virtual void action(sf::RenderWindow& window);
    virtual ~Repeater();
};


class SnowPea : public ShooterPlant
{
public:
    SnowPea();
    SnowPea(sf::RenderWindow& window, float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    //define the pure virtual function to shoot the ice pea
    virtual void action(sf::RenderWindow& window);
    virtual ~SnowPea();
};

class Fumeshroom : public ShooterPlant
{

public:
    Fumeshroom();
    Fumeshroom(sf::RenderWindow& window, float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    //shoot the pea
    virtual void action(sf::RenderWindow& window);
    virtual ~Fumeshroom();
};

class Cherrybomb : public Plant
{
private:
    sf::Clock explosionClock;
public:
    Cherrybomb();
    Cherrybomb(sf::RenderWindow& window, float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    virtual void action(sf::RenderWindow& window);
};

class Wallnut : public Plant 
{
private:
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 32; // Total number of frames in the animation
public:
    Wallnut();
    Wallnut(sf::RenderWindow& window, float x, float y);
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    virtual void action(sf::RenderWindow& window);
    void animate();
};

class Sunflower : public Plant
{
private:
    Sun sun;
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 54; // Total number of frames in the animation
public:
    Sunflower();
    Sunflower(sf::RenderWindow& window, float x, float y);
    Sun& getSun();
    int getSunCount();
    // draw the sprite
    virtual void draw(sf::RenderWindow& window);
    void animate();
    //define the pure virtual function to produce sun
    virtual void action(sf::RenderWindow& window);
};

class PlantFactory
{
    Plant** Plant_ptr;
    int size; //no.of plants
    int current; //index
public:
    PlantFactory();
    int getCost(int type);
    Plant** getPlantArray();
    int getPlantIndex();

    void addPlants(float x, float y, int type, sf::RenderWindow& window);

    Plant* selectPlants(float x, float y, sf::RenderWindow& window, int type);

    //function to see if plant has been placed within range
    bool plantPlaced(float& mouseX, float& mouseY); //pass by reference to change the coordinates

   
    // functions for centering the coordinates on the sqaures of the grid
    float plantXCoord(float mouseX);

    float plantYCoord(float mouseY);

    virtual ~PlantFactory();

};

