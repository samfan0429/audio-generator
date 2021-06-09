# include "Menu.h"
# include <iostream>

// Private functions
void Menu::initvariables()
{
    this->setPosition(sf::Vector2f(3,3));
    this->setSize(sf::Vector2f(1434,100));
    this->setFillColor(sf::Color(192,192,192));
    this->setOutlineThickness(3);
    this->setOutlineColor(sf::Color(112,128,144));
}

// Public

// Constructor & Destructor
Menu::Menu()
{
    this->initvariables();
    // this->draw();
}

Menu::~Menu()
{
    // std::cout << "Window deleted" << std::endl;
}

void Menu::updatePressed(sf::Vector2f mouse_pos)
{
    
}

void Menu::draw()
{
    this->canvas->draw(*this);
}

void Menu::setCanvas(sf::RenderWindow* window)
{
    this->canvas = window;
}