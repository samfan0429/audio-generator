#ifndef SPACE_H
#define SPACE_H

# include <vector>
# include <memory>
# include <iostream>
# include <thread>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

// # include "GraphicObject/Key.h"
# include "Keyboard.h"
# include "Mixer.h"

// Main Application
class Space
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;

    bool dragged;

    std::shared_ptr<Keyboard> keys;
    std::shared_ptr<Mixer> mixer;
    
    void initvariables();
    void initWindow();
    
public:
    Space();

    virtual ~Space();

    const bool running() const;

    void pollEvents();
    void update();
    void render();
};
 
#endif