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
        this->former = 0;
        this->curr = 0;
        // this->setOrigin(sf::Vector2f(50, 50));
    }
}

// Public

// Constructor & Destructor
Roller::Roller(float val)
{   
    this->maxVal = val;
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

void Roller::changeFormer()
{
    former = round(this->getRotation()*100)/100;
    // std::cout << "Previous is "<< former << " degrees." << std::endl;
}

void Roller::updateCurr()
{
    this->curr = this->getRotation()/360.0*maxVal;
    // std::cout << "Current Value is " << this->curr << std::endl;
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
    // std::cout<< this->getRotation() << std::endl;
}