# include "Space.h"
# include <iostream>

// Private functions
void Space::initvariables()
{
    // this->soundMaker = std::make_shared<Generator>(440, 0.9, "Sine");
    this->soundMakers[0] = std::make_shared<Generator>(261.6, 0.9, "Sine");
    this->soundMakers[1] = std::make_shared<Generator>(293.3, 0.9, "Sine");
    this->soundMakers[2] = std::make_shared<Generator>(329.6, 0.9, "Sine");
    this->soundMakers[3] = std::make_shared<Generator>(349.2, 0.9, "Sine");
    this->soundMakers[4] = std::make_shared<Generator>(391.9954, 0.9, "Sine");
    this->soundMakers[5] = std::make_shared<Generator>(440.0, 0.9, "Sine");
    this->soundMakers[6] = std::make_shared<Generator>(493.9, 0.9, "Sine");
    this->soundMakers[7] = std::make_shared<Generator>(523.3, 0.9, "Sine");


    this->window = nullptr;
}

void Space::initWindow()
{
    this->videomode.height = 720;
    this->videomode.width = 1280;
    this->window = new sf::RenderWindow(this->videomode, "Audio-Generator",sf::Style::Titlebar | sf::Style::Close);
    // this->window->setFramerateLimit(60);
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
                else if(this->ev.key.code==sf::Keyboard::Num1){
                    soundMakers[0]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num2){
                    soundMakers[1]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num3){
                    soundMakers[2]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num4){
                    soundMakers[3]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num5){
                    soundMakers[4]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num6){
                    soundMakers[5]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num7){
                    soundMakers[6]->play();
                }
                else if(this->ev.key.code==sf::Keyboard::Num8){
                    soundMakers[7]->play();
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