# include "Key.h"
# include <iostream>

// Private functions
void Key::initvariables(int n)
{
    this->setSize(sf::Vector2f(27.6,150));
    this->n = n;
}

// Public

// Constructor & Destructor
Key::Key(int n)
{   
    this->initvariables(n);
}

Key::~Key()
{
    // std::cout << "Window deleted" << std::endl;
}

void Key::update()
{

}

int Key::getN()
{
    return this->n;
}