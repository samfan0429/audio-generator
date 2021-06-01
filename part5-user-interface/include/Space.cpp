# include "Space.h"
# include <iostream>

// Private functions
void Space::initvariables()
{
    int count = 4;
    float currX = 360 ,currY = 540;
    c = std::make_shared<Key>(count);
    c->setFillColor(sf::Color::White);
    c->setOutlineThickness(2);
    c->setOutlineColor(sf::Color::Black);
    c->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    // std::cout << "C is " << c->getN() << std::endl;
    count+=2;
    // std::cout << "Current count is " << count << std::endl;
    d = std::make_shared<Key>(count);
    d->setFillColor(sf::Color::White);
    d->setOutlineThickness(2);
    d->setOutlineColor(sf::Color::Black);
    d->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    count+=2;
    // std::cout << "D is " << d->getN() << std::endl;
    
    e = std::make_shared<Key>(count++);
    e->setFillColor(sf::Color::White);
    e->setOutlineThickness(2);
    e->setOutlineColor(sf::Color::Black);
    e->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    // std::cout << "E is " << e->getN() << std::endl;
    
    f = std::make_shared<Key>(count);
    f->setFillColor(sf::Color::White);
    f->setOutlineThickness(2);
    f->setOutlineColor(sf::Color::Black);
    f->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    count+=2;
    // std::cout << "F is " << f->getN() << std::endl;
    
    g = std::make_shared<Key>(count);
    g->setFillColor(sf::Color::White);
    g->setOutlineThickness(2);
    g->setOutlineColor(sf::Color::Black);
    g->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    count+=2;
    // std::cout << "G is " << g->getN() << std::endl;
    
    a = std::make_shared<Key>(count);
    a->setFillColor(sf::Color::White);
    a->setOutlineThickness(2);
    a->setOutlineColor(sf::Color::Black);
    a->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    count+=2;
    // std::cout << "A is " << a->getN() << std::endl;
    
    b = std::make_shared<Key>(count++);
    b->setFillColor(sf::Color::White);
    b->setOutlineThickness(2);
    b->setOutlineColor(sf::Color::Black);
    b->setPosition(sf::Vector2f(currX,currY));
    currX+=24.6;
    // std::cout << "B is " << b->getN() << std::endl;
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
    this->window->clear(sf::Color(255,255,255,255));

    this->window->draw(*c);
    this->window->draw(*d);
    this->window->draw(*e);
    this->window->draw(*f);
    this->window->draw(*g);
    this->window->draw(*a);
    this->window->draw(*b);

    this->window->display();
}