# include "Button.h"

// Private functions
void Button::initvariables()
{
    this->setSize(sf::Vector2f(50,50));
    this->setOutlineThickness(3);
}

// Public

// Constructor & Destructor
Button::Button()
{   
    this->initvariables();
}

Button::~Button()
{
    // std::cout << "Window deleted" << std::endl;
}

void Button::update()
{

}