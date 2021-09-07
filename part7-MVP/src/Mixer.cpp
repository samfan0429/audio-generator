# include "Mixer.h"
# include <iostream>

// Private functions
void Mixer::initvariables(std::shared_ptr<SM> dat)
{
    this->dat = dat;

    this->setPosition(sf::Vector2f(3,3));
    this->setSize(sf::Vector2f(1434,400));
    this->setFillColor(sf::Color(192,192,192));
    this->setOutlineThickness(3);
    this->setOutlineColor(sf::Color(112,128,144));

    freqDragged = nullptr;
    ampDragged = nullptr;

    this->rotCount = 7;

    sf::Vector2f* center = new sf::Vector2f(50.0f,50.0f);

    valDisplays.reserve(rotCount);
    this->setFont();

    freqRollers.reserve(rotCount);
    initFreqRollers(center);

    ampRollers.reserve(rotCount);
    initAmpRollers(center);

}

void Mixer::setFont()
{
    
    if(!this->font.loadFromFile("resource/font/arial.ttf"))
    {
        std::cout << "Cannot Find Font in Mixer" << std::endl;
    }
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

        std::shared_ptr<sf::Text> tmp1 = std::make_shared<sf::Text>();
        tmp1->setFont(this->font);
        tmp1->setString("0");
        tmp1->setCharacterSize(24);
        tmp1->setFillColor(sf::Color::White);
        tmp1->setStyle(sf::Text::Bold);
        tmp1->setPosition(sf::Vector2f(x,y+60));
        this->valDisplays.push_back(tmp1);

        std::shared_ptr<Roller> tmp = std::make_shared<Roller>(4096.0f, tmp1,i);
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
        std::shared_ptr<sf::Text> tmp1 = std::make_shared<sf::Text>();
        tmp1->setFont(this->font);
        tmp1->setString("0");
        tmp1->setCharacterSize(24);
        tmp1->setFillColor(sf::Color::White);
        tmp1->setStyle(sf::Text::Bold);
        tmp1->setPosition(sf::Vector2f(x,y+60));
        this->valDisplays.push_back(tmp1);

        std::shared_ptr<Roller> tmp = std::make_shared<Roller>(1.5f, tmp1, i);
        tmp->setOrigin(*center);
        tmp->setPosition(sf::Vector2f(x, y));
        this->ampRollers.push_back(tmp);
        x+=200;
    }
}

// Public

// Constructor & Destructor
Mixer::Mixer(std::shared_ptr<SM> dat)
{
    this->initvariables(dat);
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
            this->freqDragged = this->freqRollers[i];
            this->freqDragged->changeFormer();
            return true;
        }
        else if(this->ampRollers[i]->getGlobalBounds().contains(mouse_pos))
        {
            // std::cout << "I got clicked " << std::endl;
            this->ampDragged = this->ampRollers[i];
            this->ampDragged->changeFormer();
            return true;
        }
    }
    return false;
}

void Mixer::updateDragged(sf::Vector2f mouse_pos)
{
    if(this->freqDragged!=nullptr)
    {
        this->freqDragged->update(mouse_pos);
        this->freqDragged->updateCurr();
        this->dat->freqs[this->freqDragged->getID()]=this->freqDragged->getCurr();
    } else if(this->ampDragged!=nullptr)
    {
        this->ampDragged->update(mouse_pos);
        this->ampDragged->updateCurr();
        this->dat->amps[this->ampDragged->getID()]=this->ampDragged->getCurr();
    }

}

void Mixer::updateReleased()
{
    if(this->freqDragged!=nullptr)
    {
        this->freqDragged= nullptr;
    } else if(this->ampDragged!=nullptr)
    {
        this->ampDragged = nullptr;
    }
}

void Mixer::draw()
{
    this->canvas->draw(*this);
    for(unsigned int i=0;i<rotCount;i++)
    {
        this->canvas->draw(*freqRollers[i]);
        this->canvas->draw(*valDisplays[i]);
        this->canvas->draw(*ampRollers[i]);
        this->canvas->draw(*valDisplays[i+rotCount]);
    }
}

void Mixer::setCanvas(sf::RenderWindow* window)
{
    this->canvas = window;
}

std::shared_ptr<Roller> Mixer::getFreqDragged()
{
    return this->freqDragged;
}

std::shared_ptr<Roller> Mixer::getAmpDragged()
{
    return this->ampDragged;
}