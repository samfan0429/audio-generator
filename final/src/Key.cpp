# include "Key.h"
# include <iostream>

// Private functions
void Key::initvariables()
{
    int tmp = (this->n-3)%12;
    if(this->n==2 || tmp == 2 || tmp ==4 || tmp == 7 || tmp == 9 || tmp == 11)
    {
        this->setSize(sf::Vector2f(10.0,80));
    }
    else
    {
        this->setSize(sf::Vector2f(23.9,140));
    }
    this->rails();
}

void Key::rails()
{
    this->rj = pow(2.0,(this->n-49.0)/12.0)*440;
}

// Public

// Constructor & Destructor
Key::Key(int n)
    :n(n)
{   
    // std::cout << "I am called" << this->n << std::endl;
    this->initvariables();
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

float Key::getRJ()
{
    return rj;
}