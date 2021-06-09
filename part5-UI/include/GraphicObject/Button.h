#ifndef BUTTON_H
#define BUTTON_H

# include <vector>
# include <memory>
# include <iostream>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>


// Main Application
class Button: public sf::RectangleShape
{
private:
    
    void initvariables();
    
public:
    Button();

    virtual ~Button();

    void update();

};
 
#endif