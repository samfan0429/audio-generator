# include "Space.h"
# include <iostream>

// Private functions
void Space::initvariables()
{
    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 900;
    this->videomode.width = 1440;
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
                break;
            case sf::Event::MouseButtonPressed:
                if(this->ev.mouseButton.button == sf::Mouse::Left)
                {

                }
                break;
            case sf::Event::MouseButtonReleased:
                if(this->ev.mouseButton.button == sf::Mouse::Left)
                {

                }
                break;
        }
    }
}

void Space::update()
{
    // std::cout << "Working" << std::endl;
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
    this->window->clear(sf::Color(255,255,255,255));

    this->window->display();
}