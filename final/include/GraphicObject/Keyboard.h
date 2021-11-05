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
    sf::RenderWindow* canvas;

    std::shared_ptr<SM> dat;
    bool playing[88];

    int countPlaying = 0;

    void initvariables();

    void makeCtoB(float x, float y, int oct);
    
public:
    Keyboard(std::shared_ptr<SM>);

    virtual ~Keyboard();

    void updatePressed(sf::Vector2f mouse_pos);
    void draw();
    void setCanvas(sf::RenderWindow* window);

    std::vector<std::shared_ptr<Key>> getWhites();
    std::vector<std::shared_ptr<Key>> getBlacks();

    bool getPlaying();

};
 
#endif