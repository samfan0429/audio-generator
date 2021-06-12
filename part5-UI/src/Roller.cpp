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

void Roller::update(sf::Vector2f mouse_pos)
{
    // std::cout << "new point for x before "<< mouse_pos.x << std::endl;
    // std::cout << "new point for y before "<< mouse_pos.y << std::endl;
    mouse_pos-=this->getPosition();
    // std::cout << "new point for x "<< mouse_pos.x << std::endl;
    // std::cout << "new point for y "<< mouse_pos.y << std::endl;
    // mouse_pos-=this->lastPoint;
    double ang = atan2(mouse_pos.x, (-1)*mouse_pos.y)*180.0/PI;
    // std::cout << this->lastPoint->x << std::endl;
    // std::cout << this->getPosition().x << std::endl;
    // std::cout << this->getPosition().y << std::endl;
    // std::cout << this->getRotation() << std::endl;
    this->rotate(ang-this->getRotation());
}