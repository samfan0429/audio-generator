# include "Space.h"

// Private functions
void Space::initvariables()
{
    this->obj = new Spring(100,100);
    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 720;
    this->videomode.width = 1280;
    this->window = new sf::RenderWindow(videomode, "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    // this->window->setVerticalSyncEnabled(true);
    this->window->setFramerateLimit(48);
    this->window->setActive(true);
}

// Constructor & Destructor
Space::Space()
{
    this->initvariables();
    this->initWindow();
}

Space::~Space()
{
    std::cout << "Window deleted" << std::endl;
    delete this->window;
}

// Public

const bool Space::running() const
{
    return this->window->isOpen();
}

void Space::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
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
            case sf::Event::Resized:
                glViewport(0, 0, this->ev.size.width, this->ev.size.height);
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
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->window->draw(obj->getObj());

    this->window->display();
}