# include "Mixer.h"
# include <iostream>

// Private functions
void Mixer::initvariables()
{
    this->setPosition(sf::Vector2f(3,3));
    this->setSize(sf::Vector2f(1434,200));
    this->setFillColor(sf::Color(192,192,192));
    this->setOutlineThickness(3);
    this->setOutlineColor(sf::Color(112,128,144));

    int initX = 100, initY = 100;

    this->rollers.push_back(std::make_shared<Roller>());
    this->rollers[0]->setOrigin(sf::Vector2f(50,50));
    this->rollers[0]->setPosition(sf::Vector2f(initX, initY));

}

// Public

// Constructor & Destructor
Mixer::Mixer()
{
    this->initvariables();
    // this->draw();
}

Mixer::~Mixer()
{
    // std::cout << "Window deleted" << std::endl;
}

bool Mixer::updatePressed(sf::Vector2f mouse_pos)
{
    for(unsigned int i=0; i< rollers.size();i++)
    {
        if(this->rollers[i]->getGlobalBounds().contains(mouse_pos))
        {
            // std::cout << "I got clicked " << std::endl;
            this->dragged = this->rollers[i];
            return true;
        }
    }
    return false;
}

void Mixer::updateDragged(sf::Vector2f mouse_pos)
{
    this->dragged->update(mouse_pos);
}

void Mixer::draw()
{
    this->canvas->draw(*this);
    this->canvas->draw(*rollers[0]);
}

void Mixer::setCanvas(sf::RenderWindow* window)
{
    this->canvas = window;
}

std::shared_ptr<Roller> Mixer::getDragged()
{
    return this->dragged;
}