# include "Space.h"

// Private functions
void Space::initvariables()
{
    this->dragged = false;
    this->playing = false;
    this->stopped = true;
    this->stopping = false;
    // this->keys = std::make_shared<Keyboard>();
    this->mixer = std::make_shared<Mixer>();
    
    this->play = std::make_shared<Button>("Play", sf::Vector2f(100,40), sf::Vector2f(500.0f,450.0f));
    this->stop = std::make_shared<Button>("Stop", sf::Vector2f(100,40), sf::Vector2f(700.0f,450.0f));
    
    // this->keys->draw();
    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 500;
    this->videomode.width = 1440;
    this->window = new sf::RenderWindow(this->videomode, "Audio-Generator",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(30);

    // this->keys->setCanvas(this->window);
    this->play->setCanvas(this->window);
    this->stop->setCanvas(this->window);
    this->mixer->setCanvas(this->window);
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
                    
                    if(this->mixer->getGlobalBounds().contains(translated_pos))
                    {
                        if(this->mixer->updatePressed(translated_pos))
                        {
                            // std::cout << "Roller rolling" << std::endl;
                            dragged=true;
                        }
                    }
                    else if(this->play->isClicked(translated_pos))
                    {
                        playing = true;
                        stopped = false;
                        // this->soundPlayer->start();
                        // std::cout << "Play is clicked" << std::endl;
                    }
                    else if(this->playing && this->stop->isClicked(translated_pos) )
                    {
                        stopping = true;
                    }
                }
                break;
            case sf::Event::MouseButtonReleased:
                if(this->ev.mouseButton.button == sf::Mouse::Left)
                {
                    // std::cout << "Mouse Released BB" << std::endl;
                    if(dragged)
                    {
                        // std::cout << "Roller released" << std::endl;
                        dragged=false;
                        this->mixer->updateReleased();
                    }
                    else if(stopping)
                    {
                        // playing = false;
                        stopping = false;
                        stopped = true;
                        this->play->updateReleased();
                        this->stop->updateReleased();
                    }
                }
                break;
            default:
                break;
        }
    }
}

void Space::dragEvent()
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*(this->window));
    sf::Vector2f translated_pos = this->window->mapPixelToCoords(mouse_pos);
    // std::cout << "drag working" << std::endl;
    this->mixer->updateDragged(translated_pos);
}

void Space::update()
{
    // std::cout << "Working" << std::endl;
    if(dragged) this->dragEvent();

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
    // this->keys->draw();
    this->mixer->draw();
    this->play->draw();
    this->stop->draw();

    this->window->display();
}

bool Space::getPlaying()
{
    return playing;
}

bool Space::getStopped()
{
    return this->stopped;
}