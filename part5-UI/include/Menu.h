#ifndef MENU_H
#define MENU_H

# include <vector>
# include <memory>
# include <iostream>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

# include "Button.h"

// Main Application
class Menu: public sf::RectangleShape
{
private:
    std::vector<Button> buttons;
    sf::RenderWindow* canvas;

    void initvariables();
    
public:
    Menu();

    virtual ~Menu();

    void updatePressed(sf::Vector2f mouse_pos);
    void draw();
    void setCanvas(sf::RenderWindow* window);

};
 
#endif