# include "Mixer.h"
# include <iostream>

// Private functions
void Mixer::initvariables()
{
    this->setPosition(sf::Vector2f(3,3));
    this->setSize(sf::Vector2f(1434,400));
    this->setFillColor(sf::Color(192,192,192));
    this->setOutlineThickness(3);
    this->setOutlineColor(sf::Color(112,128,144));

    this->rotCount = 7;

    sf::Vector2f* center = new sf::Vector2f(50.0f,50.0f);

    freqRollers.reserve(rotCount);
    initFreqRollers(center);

    ampRollers.reserve(rotCount);
    initAmpRollers(center);

}

void Mixer::initFreqRollers(sf::Vector2f* center)
{

    // sf::Text text;

    // // select the font
    // text.setFont(font); // font is a sf::Font
    // text.setString("Hello world");
    // text.setCharacterSize(24); // in pixels, not points!
    // text.setFillColor(sf::Color::White);
    // text.setStyle(sf::Text::Bold);

    int x = 100, y = 100;

    for(unsigned int i=0;i<rotCount;i++)
    {
        std::shared_ptr<Roller> tmp = std::make_shared<Roller>(4096.0f);
        tmp->setOrigin(*center);
        tmp->setPosition(sf::Vector2f(x, y));
        this->freqRollers.push_back(tmp);
        x+=200;
    }
}

void Mixer::initAmpRollers(sf::Vector2f* center)
{
    int x = 100, y = 300;

    for(unsigned int i=0;i<rotCount;i++)
    {
        std::shared_ptr<Roller> tmp = std::make_shared<Roller>(1.5f);
        tmp->setOrigin(*center);
        tmp->setPosition(sf::Vector2f(x, y));
        this->ampRollers.push_back(tmp);
        x+=200;
    }
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
    for(unsigned int i=0; i< rotCount;i++)
    {
        if(this->freqRollers[i]->getGlobalBounds().contains(mouse_pos))
        {
            // std::cout << "I got clicked " << std::endl;
            this->dragged = this->freqRollers[i];
            this->dragged->changeFormer();
            return true;
        }
        else if(this->ampRollers[i]->getGlobalBounds().contains(mouse_pos))
        {
            // std::cout << "I got clicked " << std::endl;
            this->dragged = this->ampRollers[i];
            this->dragged->changeFormer();
            return true;
        }
    }
    return false;
}

void Mixer::updateDragged(sf::Vector2f mouse_pos)
{
    this->dragged->update(mouse_pos);
}

void Mixer::updateReleased()
{
    this->dragged->updateCurr();
    this->dragged = nullptr;
}

void Mixer::draw()
{
    this->canvas->draw(*this);
    for(unsigned int i=0;i<rotCount;i++)
    {
        this->canvas->draw(*freqRollers[i]);
        this->canvas->draw(*ampRollers[i]);
    }
}

void Mixer::setCanvas(sf::RenderWindow* window)
{
    this->canvas = window;
}

std::shared_ptr<Roller> Mixer::getDragged()
{
    return this->dragged;
}