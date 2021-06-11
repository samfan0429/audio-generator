# include "Roller.h"

// Private functions
void Roller::initvariables()
{
    if(!file.loadFromFile("resource/buttons/roller.png"))
    {
        std::cout << "Cannot Find" << std::endl;
    }
    else
    {
        // std::cout << "Found that roller" << std::endl;
        this->setTexture(file);
        // this->setOrigin(sf::Vector2f(50, 50));
    }
}

// Public

// Constructor & Destructor
Roller::Roller()
{   
    this->initvariables();
}

Roller::~Roller()
{
    // std::cout << "Window deleted" << std::endl;
}

void Roller::fixCenter(sf::Vector2f pos)
{
    this->setOrigin(pos);
}

void Roller::update()
{
    // std::cout << this->getPosition().x << std::endl;
    // std::cout << this->getPosition().y << std::endl;
    this->rotate(30);
}