#ifndef MIXER_H
#define MIXER_H

# include <vector>
# include <memory>
# include <iostream>

# include <SFML/Graphics.hpp>
// # include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

# include "Roller.h"
# include "SM.h"

// Main Application
class Mixer: public sf::RectangleShape
{
private:
    std::vector<std::shared_ptr<Roller>> freqRollers;
    std::vector<std::shared_ptr<Roller>> ampRollers;
    std::vector<std::shared_ptr<sf::Text>> valDisplays;

    sf::Font font;
    
    std::shared_ptr<SM> dat;

    // sf::Text freq;
    // sf::Text amp;
    unsigned int rotCount;

    sf::RenderWindow* canvas;
    std::shared_ptr<Roller> freqDragged;
    std::shared_ptr<Roller> ampDragged;

    void initvariables(std::shared_ptr<SM> dat);
    void setFont();
    void initFreqRollers(sf::Vector2f* center);
    void initAmpRollers(sf::Vector2f* center);
    
public:
    Mixer(std::shared_ptr<SM> dat);

    virtual ~Mixer();

    bool updatePressed(sf::Vector2f mouse_pos);
    
    void updateDragged(sf::Vector2f mouse_pos);
    void updateReleased();

    void draw();
    void setCanvas(sf::RenderWindow* window);

    std::shared_ptr<Roller> getFreqDragged();
    std::shared_ptr<Roller> getAmpDragged();
};
 
#endif