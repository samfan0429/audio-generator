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
    std::vector<std::shared_ptr<Key>> whites;
    std::vector<std::shared_ptr<Key>> blacks;
    sf::RenderWindow* canvas;

    void initvariables();
    void makeCtoB(float x, float y, int oct);
    
public:
    Keyboard();

    virtual ~Keyboard();

    void updatePressed(sf::Vector2f mouse_pos);
    void draw();
    void setCanvas(sf::RenderWindow* window);

    std::vector<std::shared_ptr<Key>> getWhites();
    std::vector<std::shared_ptr<Key>> getBlacks();
};
 
#endif