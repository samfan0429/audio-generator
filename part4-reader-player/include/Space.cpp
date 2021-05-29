# include "Space.h"
# include <iostream>

// Private functions
void Space::initvariables()
{
    std::vector<double> tmp = {440.000, 349.228, 261.626, 293.665, 349.228,349.228};
    std::vector<double> tmp2 = {4,8,16,16,8,8};
    std::vector<int> tmp3 = {0,1,0,0,0,1};
    this->play = std::make_shared<Player>(tmp, tmp2, tmp3, 60.0/132.0);

    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 720;
    this->videomode.width = 1280;
    this->window = new sf::RenderWindow(this->videomode, "Audio-Generator",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(30);
    // this->window->setVerticalSyncEnabled(true);
}

// Constructor & Destructor
Space::Space()
{
    this->initvariables();
    this->initWindow();
}

Space::~Space()
{
    // std::cout << "Window deleted" << std::endl;
    delete this->window;
}

// Public

const bool Space::running() const
{
    return this->window->isOpen();
}

void Space::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
       
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
                else if(this->ev.key.code == sf::Keyboard::Num1)
                {
                    this->play->playSound();
                }
                break;
        }
    }
}

void Space::update()
{
    this->pollEvents();
}

void Space::render()
{
    /*
        @return void
        - clear old frame
        - render objects
        - display the new frame
    */
    // this->window->clear(sf::Color(255,255,255,255));

    this->window->display();
}