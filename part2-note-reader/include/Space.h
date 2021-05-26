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

# include <math.h>
#define TWOPI 6.283185307

# include <Generator.h>

// Main Application
class Space
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;
    
    // sf::Sound soundPlayer;
    // std::vector<sf::Int16> samples;
    // sf::SoundBuffer buffer;
    // std::shared_ptr<Generator> soundMaker;
    std::vector<std::shared_ptr<Generator>> soundMakers{std::vector<std::shared_ptr<Generator>>(8, nullptr)};

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