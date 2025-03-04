#include "SFML\Graphics.hpp"
#include "Zombie.h"

//---------ZOMBIE
Zombie::Zombie() : collidedWithPlant(false) {}
Zombie::~Zombie() {}
void Zombie::setposition(float x, float y)
{
    this->x = x;
    this->y = y;
}
void Zombie::setHealth(int h)
{
    this->health = h;
}
void Zombie::setIsAlive(bool a)
{
    this->isAlive = a;
}
float Zombie::getpositionx() {
    return this->x;
}
float Zombie::getpositiony() {
    return this->y;
}
float Zombie::getwidth() {
    return sprite.getTexture()->getSize().x;
}
float Zombie::getheight() {
    return sprite.getTexture()->getSize().y;
}
int Zombie::getHealth()
{
    return this->health;
}
bool Zombie::getIsAlive()
{
    return this->isAlive;
}
float Zombie::getSpeed()
{
    return this->speed;
}
void Zombie::setSpeed(float s)
{
    this->speed = s;
}
void Zombie::kill() //kill the zombie
{
    this->x = 20000;
    this->y = 20000;
    this->sprite.setPosition(this->x, this->y);
}
// Method to check collision with plants
bool Zombie::checkPlantCollision(Plant* plant)
{
    // check if the zombie is within the bounds of the plant and hasn't collided before
    if (plant->x <= this->x
        && plant->x + 72 >= this->x
        && plant->y >= this->y
        && plant->y <= this->y + this->getheight()
        && !collidedWithPlant)
    {
        collidedWithPlant = true; // set the flag to true to indicate collision
        return true;
    }
    return false;
}

//----SIMPLE ZOMBIE
SimpleZombie::SimpleZombie(RenderWindow& window, float initialX, float initialY)
{
    speed = 0.5; //slow speed

    health = 75; //least health for easy defeat
    isAlive = true;
    Texture texture;
    texture.loadFromFile("n.png");
    sprite.setTexture(texture);
    sprite.setPosition(initialX, initialY);
    sprite.setTextureRect(IntRect(0, 0, 110.34, 120));
    this->setposition(initialX, initialY);
    //  window.draw(sprite);
}
void SimpleZombie::draw() {}
void SimpleZombie::move(RenderWindow& window)
{
    if (isAlive)
    {
        Texture texture;
        texture.loadFromFile("n.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, 110.34, 120));

        this->x -= speed; //simple zombie speed

        this->sprite.setPosition(x, y);
        animate();
        window.draw(sprite);
    }
    else //take it off the screen once its dead
    {
        this->x = 20000;
        this->y = 20000;
        this->sprite.setPosition(this->x, this->y);
    }

}

void SimpleZombie::animate() {
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 110.34;
        int frameHeight = 120;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}

//-------FOOTBALL ZOMBIE
FootballZombie::FootballZombie(RenderWindow& window, float initialX, float initialY) {
    speed = 1.5;
    health = 100; //second least health
    isAlive = true;
    Texture texture;
    texture.loadFromFile("footballzombie.png");
    sprite.setTexture(texture);
    sprite.setPosition(initialX, initialY);
    sprite.setTextureRect(IntRect(0, 0, 96, 150));
    this->setposition(initialX, initialY);
}

void FootballZombie::move(RenderWindow& window)
{
    if (isAlive)
    {
        Texture texture;
        texture.loadFromFile("footballzombie.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, 96.55, 150));

        // Only move if cooldown time has elapsed
        if (movementTimer.getElapsedTime().asSeconds() >= movementCooldown)
            // Adjust x-coordinate based on the direction of movement
            this->x -= speed * 2; // Move left

        else
        {
            this->x += speed + 1;// Move right
            // Reset the timer
            movementTimer.restart();
        }

        this->sprite.setPosition(x, y);
        animate();
        window.draw(sprite);
    }

    else //take it off the screen once its dead
    {
        this->x = 20000;
        this->y = 20000;
        this->sprite.setPosition(this->x, this->y);
    }
}

void FootballZombie::animate() {
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 96;
        int frameHeight = 150;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}


//---------FLYING ZOMBIE
FlyingZombie::FlyingZombie(RenderWindow& window, float initialX, float initialY) {
    speed = 1; //normal
    health = 125; //more health
    isAlive = true;  //240 x  150  top left  bottom : x 250 625 y
    Texture texture;
    texture.loadFromFile("flying_zombie_sprite.png");
    sprite.setTexture(texture);
    sprite.setPosition(initialX, initialY);
    sprite.setTextureRect(IntRect(0, 0, 90, 90));
    this->setposition(initialX, initialY);
}

void FlyingZombie::move(RenderWindow& window) {
    if (isAlive)
    {
        Texture texture;
        texture.loadFromFile("flying_zombie_sprite.png");
        sprite.setTexture(texture);

        this->x -= speed;

        this->sprite.setPosition(x, y);
        window.draw(sprite);
    }
    else //take it off the screen once its dead
    {
        this->x = 20000;
        this->y = 20000;
        this->sprite.setPosition(this->x, this->y);
    }
}


//-----JACKSON (SUMMONED) ZOMBIE
JacksonZombie::JacksonZombie() { }
JacksonZombie::JacksonZombie(float initialX, float initialY) {
    speed = 1.5;
    Texture texture;
    texture.loadFromFile("jackson.png");
    sprite.setTexture(texture);
    sprite.setPosition(initialX, initialY);
    sprite.setTextureRect(IntRect(0, 0, 82, 82)); // Adjusted for integer values
    x = initialX;
    y = initialY;

}
Sprite& JacksonZombie::getSprite()
{
    return this->sprite;
}
void JacksonZombie::move(RenderWindow& window) {
    Texture texture;
    texture.loadFromFile("jackson.png");
    sprite.setTexture(texture);
    x -= speed;
    sprite.setPosition(x, y);
    animate();
    window.draw(sprite);
}

void JacksonZombie::animate() {
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 82;
        int frameHeight = 82;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}


//------DANCING ZOMBIE
DancingZombie::DancingZombie(RenderWindow& window, float initialX, float initialY)
{
    speed = 1.5; //fast speed
    health = 150; //more health, takes more hits
    isAlive = true;
    Texture texture;
    texture.loadFromFile("disco.png");
    sprite.setTexture(texture);
    sprite.setPosition(initialX, initialY);
    sprite.setTextureRect(IntRect(0, 0, 113.541, 120));
    this->setposition(initialX, initialY);
    window.draw(sprite);
    // Initialize Jackson Zombies
    float jacksonOffsetX = 50.0f; // Offset from the Dancing Zombie on the x-axis
    float jacksonOffsetY = 50.0f; // Offset from the Dancing Zombie on the y-axis
    jacksonZombies = new JacksonZombie * [4];
    for (int i = 0; i < 4; i++) {
        jacksonZombies[i] = new JacksonZombie(initialX + jacksonOffsetX * (i % 2 == 0 ? -1 : 1), initialY + jacksonOffsetY * (i / 2 == 0 ? -1 : 1));
    }
}

void DancingZombie::move(RenderWindow& window)
{
    if (isAlive)
    {
        Texture texture;
        texture.loadFromFile("disco.png");
        sprite.setTexture(texture);

        this->x -= speed; // Adjust x-coordinate

        // Ensure y-coordinate is greater than 150 before decrementing
        if (this->y > 150) {
            this->y -= 2.0 / 2; // Adjust y-coordinate less to create diagonal movement towards the left
        }

        sprite.setPosition(x, y);
        animate();
        window.draw(sprite);

        // Move and draw Jackson Zombies
        for (int i = 0; i < 4; ++i) {
            jacksonZombies[i]->move(window);
        }
    }
    else //take it off the screen once its dead
    {
        this->x = 20000;
        this->y = 20000;
        this->sprite.setPosition(this->x, this->y);
        // kill Jackson Zombies
        for (int i = 0; i < 4; ++i) {
            jacksonZombies[i]->getSprite().setPosition(this->x, this->y);
        }
    }

}
void DancingZombie::animate()
{
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 113;
        int frameHeight = 120;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}

//------ZOMBIE FACTORY
ZombieFactory::ZombieFactory() {}

void ZombieFactory::initialize(int level, RenderWindow& window)
{
    srand(time(nullptr)); // Seed the random number generator
    numZombies = create_wave(level); // Generate number of zombies for the given level
    zombie_ptr = new Zombie * [numZombies]; // Allocate memory for an array of Zombie pointers
    initialX = 240 + 1000; // Initial X position for zombies
    minY = 140; // Minimum Y position for zombies
    maxY = 540; // Maximum Y position for zombies
    // Define the specific y coordinates for the middle of each cell
    float middleYCoordinates[] = { 170, 259, 425, 520,327 };
    int numMiddleYCoordinates = sizeof(middleYCoordinates) / sizeof(middleYCoordinates[0]);

    for (int i = 0; i < numZombies; i++) {
        // Randomly select one of the middle Y coordinates
        float randomY = middleYCoordinates[rand() % numMiddleYCoordinates];
        cout << randomY << " ";
        zombie_ptr[i] = generate_random_zombie(level, window, initialX, randomY); // Generate a random zombie at a specific y coordinate
        zombie_ptr[i]->move(window); // Move the zombie
    }
    delayTime = 10000;
    delayClock.restart();

}

ZombieFactory::ZombieFactory(int level, RenderWindow& window)
{
    srand(time(nullptr)); // Seed the random number generator
    numZombies = create_wave(level); // Generate number of zombies for the given level
    zombie_ptr = new Zombie * [numZombies]; // Allocate memory for an array of Zombie pointers
    initialX = 240 + 1000; // Initial X position for zombies
    minY = 140; // Minimum Y position for zombies
    maxY = 540; // Maximum Y position for zombies
    // Define the specific y coordinates for the middle of each cell
    float middleYCoordinates[] = { 170, 259, 425, 520,327 };
    int numMiddleYCoordinates = sizeof(middleYCoordinates) / sizeof(middleYCoordinates[0]);

    for (int i = 0; i < numZombies; i++) {
        // Randomly select one of the middle Y coordinates
        float randomY = middleYCoordinates[rand() % numMiddleYCoordinates];
        cout << randomY << " ";
        zombie_ptr[i] = generate_random_zombie(level, window, initialX, randomY); // Generate a random zombie at a specific y coordinate
        zombie_ptr[i]->move(window); // Move the zombie
    }
    delayTime = 10000; //10 seconds
    delayClock.restart();
}
void ZombieFactory::moveallzombies(RenderWindow& window)
{

    static int generatedZombies = 0; //keep a static variable to retain its lifetime and be incremented
    if (generatedZombies < numZombies) //only increment until max amount of zombies to prevent going out of array bounds
    {
        if (delayClock.getElapsedTime().asMilliseconds() >= delayTime) //after the delay time has passed
        {
            generatedZombies++; //increment the number of zombies
            delayClock.restart(); //restart the clock
        }
    }

    for (int i = 0; i < generatedZombies; i++) //draw the generated zombies simultaneously
    {
        zombie_ptr[i]->move(window);
    }
}

int ZombieFactory::get_totalzombies()
{
    return numZombies;
}
Zombie** ZombieFactory::get_zombies_array()
{
    return zombie_ptr;
}
Zombie* ZombieFactory::generate_random_zombie(int level, RenderWindow& window, float initialX, float initialY)
{
    switch (level) {
    case 1:
    {
        return new SimpleZombie(window, initialX, initialY); // Only SimpleZombie for level 1
        break;
    }
    case 2:
    {
        // Add cases for level 2
        switch (rand() % 2) {
        case 0:
            return new SimpleZombie(window, initialX, initialY);
            break;
        case 1:
            return new FootballZombie(window, initialX, initialY);
            break;
        }
        break;
    }
    case 3:
    {
        // Add cases for level 3
        switch (rand() % 3) {
        case 0:
            return new SimpleZombie(window, initialX, initialY);
            break;
        case 1:
            return new FootballZombie(window, initialX, initialY);
            break;
        case 2:
            return new DancingZombie(window, initialX, initialY);
            break;
        }
        break;
    }
    case 4:
    {
        // Add cases for level 4
        switch (rand() % 4) {
        case 0:
            return new SimpleZombie(window, initialX, initialY);
            break;
        case 1:
            return new FootballZombie(window, initialX, initialY);
            break;
        case 2:
            return new DancingZombie(window, initialX, initialY);
            break;
        case 3:
            return new FlyingZombie(window, initialX, initialY);
            break;
        }
        break;
    }
    default:
        return generate_random_zombie(4, window, initialX, initialY); // For other levels, generate a random zombie as before
        break;
    }
}

int ZombieFactory::create_wave(int level)
{
    int minZombies = level * 2; // Minimum number of zombies increases with level
    int maxZombies = minZombies * 2; // Maximum number of zombies increases with level
    // Generate a random number of zombies within the specified range
    int numZombies = rand() % (maxZombies - minZombies + 1) + minZombies;
    cout << "total zombies: " << numZombies << "     ";
    return numZombies;
}
bool ZombieFactory::checkPeaZombieCollision(Zombie** zombieFactoryArray, Plant** plantArray, int totalPlants)
{
    bool collided = false;
    for (int i = 0; i < totalPlants; i++)
    {
        Pea* pea = plantArray[i]->getPea();
        for (int j = 0; j < plantArray[i]->getNumberOfPeas(); j++)
        {
            for (int k = 0; k < this->get_totalzombies(); k++)
            {
                if (pea[j].x >= zombieFactoryArray[k]->getpositionx()
                    && pea[j].x <= zombieFactoryArray[k]->getpositionx() + zombieFactoryArray[k]->getwidth() / 2
                    && pea[j].y >= zombieFactoryArray[k]->y
                    && pea[j].y <= zombieFactoryArray[k]->y + zombieFactoryArray[k]->getheight() / 2)
                {
                    //if its a snow pea
                    if (plantArray[i]->getType() == 5)
                    {
                        //slow the zombie
                        float speed = zombieFactoryArray[k]->getSpeed();
                        cout << speed << endl;
                        if (speed > 0.2) //dont let it be below 0.2
                            speed -= 0.1;
                        zombieFactoryArray[k]->setSpeed(speed);

                        //other logic is the same
                        pea[j].x = plantArray[i]->x + 30; // reset pea's x-coordinate

                        //decrement the health
                        int health = zombieFactoryArray[k]->getHealth() - 25;
                        zombieFactoryArray[k]->setHealth(health);

                        if (zombieFactoryArray[k]->getHealth() < 0) //zombie died, set its alive status
                            zombieFactoryArray[k]->setIsAlive(false);

                        collided = true;
                        break; // exit loop after resetting collided pea
                    }
                    //any other pea
                    else
                    {
                        pea[j].x = plantArray[i]->x + 30; // reset pea's x-coordinate

                        //decrement the health
                        int health = zombieFactoryArray[k]->getHealth() - 25;
                        zombieFactoryArray[k]->setHealth(health);

                        if (zombieFactoryArray[k]->getHealth() < 0) //zombie died, set its alive status
                            zombieFactoryArray[k]->setIsAlive(false);

                        collided = true;
                        break; // exit loop after resetting collided pea
                    }
                }
            }
            if (collided) // break outer loop if pea collided
                break;
        }
    }
    return collided;
}

bool ZombieFactory::checkPlantZombieCollision(Zombie** zombieFactoryArray, Plant** plantArray, int totalPlants)
{
    for (int i = 0; i < totalPlants; i++)
    {
        for (int j = 0; j < get_totalzombies(); j++)
        {
            if (zombieFactoryArray[j]->checkPlantCollision(plantArray[i])) //only consider collision once
            {
                if (plantArray[i]->getType() == 4 && plantArray[i]->getIsAlive()) // cherrybomb = explode
                {
                    for (int k = 0; k < get_totalzombies(); k++)
                    {
                        //kill the zombies in a 250 unit radius
                        if (zombieFactoryArray[k]->getpositionx() <= plantArray[i]->x + 250
                            || zombieFactoryArray[k]->getpositionx() >= plantArray[i]->x - 250
                            || zombieFactoryArray[k]->getpositiony() <= plantArray[i]->y + 250
                            || zombieFactoryArray[k]->getpositiony() >= plantArray[i]->y - 250)
                        {
                            plantArray[i]->setExploded(true);
                            zombieFactoryArray[k]->setIsAlive(false);
                            zombieFactoryArray[k]->kill();
                        }
                    }
                }
                else if (plantArray[i]->getType() != 4)
                {
                    cout << "health: " << plantArray[i]->getHealth() << endl;
                    plantArray[i]->takeDamage(10); // take 10 damage upon collision
                    return true;
                }
            }
        }
    }
}
bool ZombieFactory::reachedHouse()
{
    for (int i = 0; i < this->get_totalzombies(); i++)
    {
        if (zombie_ptr[i]->x == 100) //touches house
        {
            cout << "reached house!" << endl;
            return true;
        }
    }
    return false; //none of the zombies made it
}
ZombieFactory::~ZombieFactory()
{
    for (int i = 0; i < get_totalzombies(); i++)
        delete zombie_ptr[i];
    delete[] zombie_ptr;
}