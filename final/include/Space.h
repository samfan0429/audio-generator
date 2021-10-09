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
# include "pa.h"
# include "SM.h"

// Main Application
class Space
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;

    bool dragged, playing;

    std::shared_ptr<Keyboard> keys;
    std::shared_ptr<Mixer> mixer;
    
    void initvariables(std::shared_ptr<SM>);
    void initWindow();
    
public:
    Space(std::shared_ptr<SM>);

    virtual ~Space();

    const bool running() const;

    void dragEvent();

    void pollEvents();
    void update();
    void render();

    bool getPlaying();
};
 
#endif