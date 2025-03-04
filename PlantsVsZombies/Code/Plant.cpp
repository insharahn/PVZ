#include "SFML\Graphics.hpp"
#include "Plant.h"


//-----------PLANT-------
Plant::Plant() : health(100), isAlive(true) {}

Plant::Plant(int cost, float health) : cost(cost), health(health), isAlive(true) {}

Plant::~Plant()
{
    delete[] pea;
}

//setters
void Plant::setCost(int cost)
{
    this->cost = cost;
}
void Plant::setHealth(float health)
{
    this->health = health;
}
void Plant::setAliveStatus(bool alive)
{
    this->isAlive = alive;
}
void Plant::setNumberOfPeas(int peas)
{
    this->numberOfPeas = peas;
}
void Plant::setExploded(bool e)
{
    this->exploded = e;
}
void Plant::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}
// getters
int Plant::getCost() const
{
    return this->cost;
}
float Plant::getHealth() const
{
    return this->health;
}
bool Plant::getIsAlive() const
{
    return this->isAlive;
}
int Plant::getNumberOfPeas() const
{
    return this->numberOfPeas;
}
Pea* Plant::getPea() const
{
    return pea;
}

Sprite& Plant::getSprite()
{
    return sprite;
}
int Plant::getType() const
{
    return type;
}
void Plant::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
        isAlive = false;
}
int Plant::getSunCount()
{
    return sunCount;
}
bool Plant::getExploded()
{
    return this->exploded;
}
int Plant::sunCount = 0; //initialize the static int

//----------SHOOTER PLANT-------------
ShooterPlant::ShooterPlant() {}

void ShooterPlant::setSpeed(float speed)
{
    this->speed = speed;
}

float ShooterPlant::getSpeed() const
{
    return this->speed;
}

//-------DERIVED PLANT TYPES
//-----PEASHOOTER
Peashooter::Peashooter() {}
Peashooter::Peashooter(sf::RenderWindow& window, float x, float y)
{
    type = 1;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 100;
    health = 100;
    isAlive = true;
    numberOfPeas = 1;
    speed = 10;

    pea = new Pea[numberOfPeas];
    pea[0].x = this->x + 30;
    pea[0].y = this->y;
}
void Peashooter::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    sprite.setPosition(this->x, this->y);

    //set the pea's coordinates relative
    pea[0].x = this->x + 30;
    pea[0].y = this->y;
}
// draw the sprite
void Peashooter::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        //draw the peashooter
        sf::Texture peashooterTexture;
        if (!peashooterTexture.loadFromFile("peashooter.png")) //frozen pea
            cout << "Failed to load peashooter." << endl;
        sprite.setTexture(peashooterTexture);
        window.draw(sprite);
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}
//define the pure virtual function to shoot the peas
void Peashooter::action(sf::RenderWindow& window)
{
    for (int i = 0; i < numberOfPeas; i++)
    {
        //load the texture of the pea so it can be called with the window open
        sf::Texture peaTexture;
        peaTexture.loadFromFile("pea.png");
        pea[i].getSprite().setTexture(peaTexture);

        //draw the pea
        window.draw(pea[i].getSprite());

        //move the pea
        pea[i].updatePosition(this->speed);

        if (pea[i].x > 1280) //pea reaches the edge of the screen
        {
            pea[i].x = this->x + 30; //set coordinates of pea in front of snout again
        }
    }
}
Peashooter::~Peashooter()
{
    delete[] pea;
}

//-----REPEATER
Repeater::Repeater() {}
Repeater::Repeater(sf::RenderWindow& window, float x, float y)
{
    type = 6;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 200;
    health = 100;
    isAlive = true;
    numberOfPeas = 2;
    speed = 10;

    pea = new Pea[numberOfPeas];
    //positions of peas are slightly apart
    pea[0].x = this->x + 30;
    pea[0].y = this->y;
    pea[1].x = this->x + 70;
    pea[1].y = this->y;
}
// draw the sprite
void Repeater::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        sf::Texture repeaterTexture;
        if (!repeaterTexture.loadFromFile("repeater.png"))
            cout << "Failed to load repeater." << endl;
        sprite.setTexture(repeaterTexture);
        window.draw(sprite);
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}
//define the pure virtual function to shoot the peas
void Repeater::action(sf::RenderWindow& window)
{
    for (int i = 0; i < numberOfPeas; i++)
    {
        sf::Texture peaTexture;
        peaTexture.loadFromFile("pea.png");
        pea[i].getSprite().setTexture(peaTexture);

        window.draw(pea[i].getSprite());

        pea[i].updatePosition(this->speed);

        if (pea[i].x > 1280) // pea reaches the edge of the screen
        {
            pea[i].x = this->x + 30; // set coordinates of pea in front of snout again
        }
    }
}
Repeater::~Repeater()
{
    delete[] pea;
}

//--------SNOWPEA
SnowPea::SnowPea() {}
SnowPea::SnowPea(sf::RenderWindow& window, float x, float y)
{
    type = 5;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 175;
    health = 100;
    isAlive = true;
    numberOfPeas = 1;
    speed = 10;

    pea = new Pea[numberOfPeas];
    pea[0].x = this->x + 30;
    pea[0].y = this->y;
}
// draw the sprite
void SnowPea::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        //draw the snowpea
        sf::Texture snowpeaTexture;
        if (!snowpeaTexture.loadFromFile("snowpea.png"))
            cout << "Failed to load snowpea." << endl;
        sprite.setTexture(snowpeaTexture);
        window.draw(this->getSprite());
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}
//define the pure virtual function to shoot the ice pea
void SnowPea::action(sf::RenderWindow& window)
{
    for (int i = 0; i < numberOfPeas; i++)
    {
        //load the texture of the pea so it can be called with the window open
        sf::Texture peaTexture;
        peaTexture.loadFromFile("peaIce.png");
        pea[i].getSprite().setTexture(peaTexture);

        //draw the pea
        window.draw(pea[i].getSprite());

        //move the pea
        pea[i].updatePosition(this->speed);

        if (pea[i].x > 1280) //pea reaches the edge of the screen
        {
            pea[i].x = this->x + 30; //set coordinates of pea in front of snout again
        }
    }
}
SnowPea::~SnowPea()
{
    delete[] pea;
}

//---------FUMESHROOM
Fumeshroom::Fumeshroom() {}
Fumeshroom::Fumeshroom(sf::RenderWindow& window, float x, float y)
{
    type = 7;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 100;
    health = 100;
    isAlive = true;
    numberOfPeas = 1;
    speed = 10;

    pea = new Pea[numberOfPeas];
    pea[0].x = this->x + 30;
    pea[0].y = this->y;

}

// draw the sprite
void Fumeshroom::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        sf::Texture fumeshroomTexture;
        if (!fumeshroomTexture.loadFromFile("fumeshroom.png"))
            cout << "Failed to load fumeshroom." << endl;
        sprite.setTexture(fumeshroomTexture);
        window.draw(this->getSprite());
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}

//shoot the pea
void Fumeshroom::action(sf::RenderWindow& window)
{
    for (int i = 0; i < numberOfPeas; i++)
    {
        //load the texture of the pea so it can be called with the window open
        sf::Texture peaTexture;
        peaTexture.loadFromFile("purplePea.png");
        pea[i].getSprite().setTexture(peaTexture);

        //draw the pea
        window.draw(pea[i].getSprite());

        //move the pea
        pea[i].updatePosition(this->speed);

        if (pea[i].x > 1280) //pea reaches the edge of the screen
        {
            pea[i].x = this->x + 40; //set coordinates of pea in front of snout again
        }
    }
}
Fumeshroom::~Fumeshroom()
{
    delete[] pea;
}

//---------CHERRYBOMB
Cherrybomb::Cherrybomb() {}
Cherrybomb::Cherrybomb(sf::RenderWindow& window, float x, float y)
{
    type = 4;

    numberOfPeas = 0;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 150;
    health = 100;
    isAlive = true;

    explosionClock.restart();
    exploded = false;

}
// draw the sprite
void Cherrybomb::draw(sf::RenderWindow& window)
{
    if (isAlive && !exploded)
    {
        cout << "here again" << endl;
        //draw the cherrybomb
        sf::Texture cherrybombTexture;
        if (!cherrybombTexture.loadFromFile("cherrybomb.png"))
            cout << "Failed to load cherrybomb." << endl;
        sprite.setTexture(cherrybombTexture);
        window.draw(this->getSprite());
    }
    if (isAlive && exploded)
    {
        cout << "here exploded" << endl;

        //draw the cherrybomb explosion
        sf::Texture explosionTexture;
        if (!explosionTexture.loadFromFile("explosion.png"))
            cout << "Failed to load explosion." << endl;
        sprite.setTexture(explosionTexture);
        window.draw(this->getSprite());

        int explosionTime = 6000; // 6 seconds of explosion
        if (explosionClock.getElapsedTime().asMilliseconds() >= explosionTime)
        {
            isAlive = false;
        }
        if (!isAlive)
        {
            this->x = 20000;
            this->y = 20000;
            sprite.setPosition(this->x, this->y);
        }
    }
}
void Cherrybomb::action(sf::RenderWindow& window)
{
    //does nothing but explode, which occurs upon collision so this function has no implementation
}

//--------WALLNUT
Wallnut::Wallnut() {}
Wallnut::Wallnut(sf::RenderWindow& window, float x, float y)
{
    type = 3;

    numberOfPeas = 0;

    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 50;
    health = 100;
    isAlive = true;

}
// draw the sprite
void Wallnut::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        //draw the wallnut
        sf::Texture wallnutTexture;
        if (!wallnutTexture.loadFromFile("spritesheet.png"))
            cout << "Failed to load wallnut." << endl;
        sprite.setTexture(wallnutTexture);
        sprite.setTextureRect(sf::IntRect(0, 0, 59, 81));
        action(window);
        window.draw(this->getSprite());
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}
void Wallnut::action(sf::RenderWindow& window)
{
    //roll
    this->x += 2;
    setPosition(x, y);
    animate();

}
void Wallnut::animate()
{
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 59;
        int frameHeight = 81;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}

//-------SUNFLOWER
Sunflower::Sunflower() {}
Sunflower::Sunflower(sf::RenderWindow& window, float x, float y)
{
    this->x = x;
    this->y = y;

    sprite.setPosition(this->x, this->y);

    cost = 100;
    health = 100;
    isAlive = true;

    //initialize the sun
    //set the sun's coordinates to slightly in front of and above the sunflowers
    sun.x = this->x + 30;
    sun.y = this->y - 20;
    sun.setProducingTime(10000); //set time to ten seconds
    sun.getProducingTimeClock().restart(); //reset the clock
}
Sun& Sunflower::getSun() { return this->sun; }
int Sunflower::getSunCount() { return this->sunCount; }
// draw the sprite
void Sunflower::draw(sf::RenderWindow& window)
{
    if (isAlive)
    {
        //load the texture of the sunflower
        sf::Texture sunflowerTexture;
        sunflowerTexture.loadFromFile("sunflower.png");
        sprite.setTexture(sunflowerTexture);
        sprite.setTextureRect(IntRect(0, 0, 74, 54));
        //draw the sunflower
        animate();
        window.draw(sprite);
    }
    else //kill the sprite
    {
        this->x = 20000;
        this->y = 20000;
        sprite.setPosition(x, y);
    }
}
void Sunflower::animate() {
    // Update frame based on elapsed time
    if (clock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % numFrames;
        // Calculate the rectangle for the current frame
        int frameWidth = 74;
        int frameHeight = 75;
        sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, 0, frameWidth, frameHeight));
        clock.restart(); // Restart the clock
    }
}
//define the pure virtual function to produce sun
void Sunflower::action(sf::RenderWindow& window)
{
    if (sun.getProducingTimeClock().getElapsedTime().asMilliseconds() >= sun.getProducingTime()) //produce sun only every 10 seconds
    {
        //the input class determines if the sun is collected
        MouseInput* m = new MouseInput(window, &getSun());
        m->handleInput(window);

        //draw the sun sprite
        //load the texture of the sun
        sf::Texture sunTexture;
        sunTexture.loadFromFile("sun.png");
        sun.getSprite().setTexture(sunTexture);

        //draw the sun
        window.draw(sun.getSprite());

        //let the sun move down slowly
        sun.moveSun();

        if (!sun.getExists()) //restart the timer once the sun no longer exists: reaches edge of lawn or is collected
        {
            //reset the coordinates the sun's coordinates to slightly in front of and above the sunflowers
            sun.x = this->x + 30;
            sun.y = this->y - 20;

            sun.getProducingTimeClock().restart();  //restart the timer

            sun.setExists(true); //so that it can be redrawn 

            sunCount += 25;
        }

    }
}


//-----------PLANT FACTORY
PlantFactory::PlantFactory()
{
    size = 45;
    Plant_ptr = new Plant * [size];//9*5
    current = 0;
}
//function to get the cost of each plant so that a plant can be planted based on sun count
int PlantFactory::getCost(int type)
{
    switch (type)
    {
    case 1: //peashooter
    {
        return 100;
        break;
    }
    case 2: //sunflower
    {
        return 50;
        break;
    }
    case 3: //wallnut
    {
        return 50;
        break;
    }
    case 4: //cherrybomb
    {
        return 150;
        break;
    }
    case 5: //snowpea
    {
        return 175;
        break;
    }
    case 6: //repeater
    {
        return 200;
        break;
    }
    case 7: //fumeshroom
    {
        return 100;
        break;
    }
    default:
        break;
    }
}

Plant** PlantFactory::getPlantArray()
{
    return Plant_ptr;
}
int PlantFactory::getPlantIndex()
{
    return current;
}

void PlantFactory::addPlants(float x, float y, int type, sf::RenderWindow& window)
{
    if (current < size)
    {
        Plant_ptr[current] = selectPlants(x, y, window, type);
        current++; //move index forward after adding
    }
}

Plant* PlantFactory::selectPlants(float x, float y, sf::RenderWindow& window, int type)
{
    switch (type)
    {
    case 1: //peashooter
    {
        return new Peashooter(window, x, y);
        break;
    }
    case 2: //sunflower
    {
        return new Sunflower(window, x, y);
        break;
    }
    case 3: //wallnut
    {
        return new Wallnut(window, x, y);
        break;
    }
    case 4: //cherrybomb
    {
        return new Cherrybomb(window, x, y);
        break;
    }
    case 5: //snowpea
    {
        return new SnowPea(window, x, y);
        break;
    }
    case 6: //repeater
    {
        return new Repeater(window, x, y);
        break;
    }
    case 7: //fumeshroom
    {
        return new Fumeshroom(window, x, y);
        break;
    }
    default:
    {
        break;
    }

    }
}

//function to see if plant has been placed within range
bool PlantFactory::plantPlaced(float& mouseX, float& mouseY) //pass by reference to change the coordinates
{
    if (mouseX >= 240 && mouseX <= 1050 && mouseY <= 625 && mouseY >= 175) //inside the bounds
    {
        //change the coordinates to center within the grid
        mouseX = plantXCoord(mouseX);
        mouseY = plantYCoord(mouseY);
        return true;
    }
    else
        return false;
}

// functions for centering the coordinates on the sqaures of the grid
float PlantFactory::plantXCoord(float mouseX)
{
    int plantX = mouseX - 36; // mouse click relative to png
    // center the x coordinate
    if (plantX >= 230 && plantX <= 320) // first box
    {
        plantX = 275; // center
    }
    else if (plantX >= 320 && plantX <= 400)
    {
        plantX = 360;
    }
    else if (plantX >= 400 && plantX <= 487)
    {
        plantX = 450;
    }
    else if (plantX >= 487 && plantX <= 574)
    {
        plantX = 537;
    }
    else if (plantX >= 574 && plantX <= 661)
    {
        plantX = 624;
    }
    else if (plantX >= 661 && plantX <= 748)
    {
        plantX = 711;
    }
    else if (plantX >= 748 && plantX <= 835)
    {
        plantX = 798;
    }
    else if (plantX >= 835 && plantX <= 922)
    {
        plantX = 875;
    }
    else if (plantX >= 922 && plantX <= 1009)
    {
        plantX = 955;
    }
    return plantX;
}

float PlantFactory::plantYCoord(float mouseY)
{
    int plantY = mouseY - 36;
    // set the y coordinate in the center
    if (plantY >= 176 && plantY <= 267) //first box
    {
        plantY = 210; //center
    }
    else if (plantY >= 267 && plantY <= 355)
    {
        plantY = 305;
    }
    else if (plantY >= 355 && plantY <= 443)
    {
        plantY = 390;
    }
    else if (plantY >= 443 && plantY <= 529)
    {
        plantY = 480;
    }
    else if (plantY >= 529 && plantY <= 625)
    {
        plantY = 567;
    }
    return plantY;
}

PlantFactory::~PlantFactory()
{
    for (int i = 0; i < this->size; i++)
        delete Plant_ptr[i];
    delete[] Plant_ptr;
}
