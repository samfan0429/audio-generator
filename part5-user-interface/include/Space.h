#ifndef SPACE_H
#define SPACE_H

# include <vector>
# include <memory>
# include <iostream>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

# include "GraphicObject/Key.h"


// Main Application
class Space
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;

    std::shared_ptr<Key> c;
    std::shared_ptr<Key> d;
    std::shared_ptr<Key> e;
    std::shared_ptr<Key> f;
    std::shared_ptr<Key> g;
    std::shared_ptr<Key> a;
    std::shared_ptr<Key> b;
    
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