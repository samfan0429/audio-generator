#ifndef KEYBOARD_H
#define KEYBOARD_H

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
class Keyboard
{
private:
    std::vector<std::shared_ptr<Key>> keys;
    
    void initvariables();
    
public:
    Keyboard();

    virtual ~Keyboard();

    void update();
};
 
#endif