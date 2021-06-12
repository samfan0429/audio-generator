#ifndef ROLLER_H
#define ROLLER_H

# include <vector>
# include <memory>
# include <iostream>
# include <math.h> 

#define PI 3.14159265

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>


// Main Application
class Roller: public sf::Sprite
{
private:
    sf::Texture file;
    sf::Vector2f lastPoint;

    void initvariables();
    
public:
    Roller();

    virtual ~Roller();


    void fixCenter(sf::Vector2f pos);

    void update(sf::Vector2f mouse_pos);

};
 
#endif