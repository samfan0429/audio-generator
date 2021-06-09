# include "Space.h"
# include <iostream>

// Private functions
void Space::initvariables()
{
    this->keys = std::make_shared<Keyboard>();
    this->menu = std::make_shared<Menu>();
    // this->t.setSize(sf::Vector2f(500, 600));
    // this->t.setFillColor(sf::Color::Red);
    // this->t.setOutlineThickness(7);
    // this->t.setOutlineColor(sf::Color::Black);
    // this->t.setPosition(sf::Vector2f(500, 600));
    
    // this->keys->draw();
    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 900;
    this->videomode.width = 1440;
    this->window = new sf::RenderWindow(this->videomode, "Audio-Generator",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(30);

    this->keys->setCanvas(this->window);
    this->menu->setCanvas(this->window);
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
                    // std::cout << "Mouse Clicked BB" << std::endl;
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*(this->window));
                    sf::Vector2f translated_pos = this->window->mapPixelToCoords(mouse_pos);
                    this->keys->updatePressed(translated_pos);
                    // std::cout << mouse_pos.x << "   " << mouse_pos.y << std::endl;

                }
                break;
            case sf::Event::MouseButtonReleased:
                if(this->ev.mouseButton.button == sf::Mouse::Left)
                {
                    // std::cout << "Mouse Released BB" << std::endl;
                    this->keys->updateReleased();
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

    // for(auto &p: this->keys->getKeys())
    // {
    //     window
    // }
    // std::vector<std::shared_ptr<Key>> keys = this->keys->getKeys();

    // for(auto p:keys)
    // {
    //     this->window->draw(*p);
    // }

    // this->window->draw(this->t);
    this->keys->draw();
    this->menu->draw();

    this->window->display();
}