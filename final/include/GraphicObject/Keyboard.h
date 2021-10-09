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

# include "SM.h"
# include "Key.h"


// Main Application
class Keyboard
{
private:
    std::vector<std::shared_ptr<Key>> whites;
    std::vector<std::shared_ptr<Key>> blacks;
    std::shared_ptr<Key> pressed;
    sf::RenderWindow* canvas;

    std::shared_ptr<SM> dat;

    int countPlaying;

    void initvariables();
    void makeCtoB(float x, float y, int oct);
    
public:
    Keyboard(std::shared_ptr<SM>);

    virtual ~Keyboard();

    bool updatePressed(sf::Vector2f mouse_pos);
    void updateReleased();
    void draw();
    void setCanvas(sf::RenderWindow* window);

    std::vector<std::shared_ptr<Key>> getWhites();
    std::vector<std::shared_ptr<Key>> getBlacks();
};
 
#endif