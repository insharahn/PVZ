#include <iostream>
#include <SFML/Graphics.hpp> 
#include "coordinates.h"
#include "Plant.h"

using namespace std;
using namespace sf;

// Base class for all types of zombies
class Zombie : public coordinates {
protected:
    Sprite sprite; // Sprite for rendering
    float speed;
    int health;
    bool isAlive;
    bool collidedWithPlant; //flag to help keep track of the zombie colliding with the plant just one time
public:
    Zombie();
    virtual ~Zombie();
    virtual void move(RenderWindow& window) = 0;
    void setposition(float x, float y);
    void setHealth(int h);
    void setIsAlive(bool a);
    float getpositionx();
    float getpositiony();
    float getwidth();
    float getheight();
    int getHealth();
    bool getIsAlive();
    float getSpeed();
    void setSpeed(float s);
    void kill();
    // Method to check collision with plants
    bool checkPlantCollision(Plant* plant);
};

class SimpleZombie : public Zombie {
private:
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 29; // Total number of frames in the animation
public:
    SimpleZombie(RenderWindow& window, float initialX, float initialY);
    void draw();
    void move(RenderWindow& window);

    void animate();
};

class FootballZombie : public Zombie {
private:
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 29; // Total number of frames in the animation
    sf::Clock movementTimer; // Timer for controlling movement cooldown
    float movementCooldown = 1.0f; // Cooldown duration in seconds
public:
    FootballZombie(RenderWindow& window, float initialX, float initialY);
    void move(RenderWindow& window);
    void animate();
};

class FlyingZombie : public Zombie {
public:
    FlyingZombie(RenderWindow& window, float initialX, float initialY);
    void move(RenderWindow& window);
};

class JacksonZombie : public Zombie {
private:
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 34; // Total number of frames in the animation
    float x, y; // Position of the zombie
    sf::Sprite sprite; // Sprite for the zombie

public:
    JacksonZombie();
    JacksonZombie(float initialX, float initialY);
    Sprite& getSprite();
    void move(RenderWindow& window);
    void animate();
};

class DancingZombie : public Zombie {
private:
    sf::Clock clock; // Clock for controlling animation frame change
    float frameDuration = 0.025f; // Duration between frame changes in seconds
    int currentFrame = 0; // Current frame index
    int numFrames = 96; // Total number of frames in the animation
    JacksonZombie** jacksonZombies;
public:
    DancingZombie(RenderWindow& window, float initialX, float initialY);
    void move(RenderWindow& window);
    void animate();
};


class ZombieFactory {
private:
    sf::Clock delayClock;
    int delayTime;
    Zombie** zombie_ptr;
    int numZombies; // Store the number of zombies created
    float initialX; // Initial X position for zombies
    float minY; // Minimum Y position for zombies
    float maxY; // Maximum Y position for zombies

public:
    ZombieFactory();
    void initialize(int level, RenderWindow& window);
    ZombieFactory(int level, RenderWindow& window);
    void moveallzombies(RenderWindow& window);
    int get_totalzombies();
    Zombie** get_zombies_array();
    Zombie* generate_random_zombie(int level, RenderWindow& window, float initialX, float initialY);
    int create_wave(int level);
    bool checkPeaZombieCollision(Zombie** zombieFactoryArray, Plant** plantArray, int totalPlants);
    bool checkPlantZombieCollision(Zombie** zombieFactoryArray, Plant** plantArray, int totalPlants);
    bool reachedHouse();
    virtual ~ZombieFactory();
};