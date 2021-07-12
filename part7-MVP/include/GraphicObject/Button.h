#ifndef BUTTON_H
#define BUTTON_H

# include <vector>
# include <memory>
# include <iostream>
# include <math.h> 
# include <string>

#define PI 3.14159265

# include <SFML/Graphics.hpp>
// # include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>


// Main Application
class Button
{
private:
    std::shared_ptr<sf::RectangleShape> tile;
    std::shared_ptr<sf::Text> text;
    sf::RenderWindow* canvas;
    sf::Font font;
    
    bool clicked;
    std::string name;

    void initvariables(sf::Vector2f size, sf::Vector2f position);
    void setRectangle(sf::Vector2f size, sf::Vector2f position);
    void setText(sf::Vector2f position);
    
public:
    Button(std::string name, sf::Vector2f size, sf::Vector2f position);

    virtual ~Button();

    bool isClicked(sf::Vector2f mouse_pos);
    bool getClicked();

    void setCanvas(sf::RenderWindow* window);
    void draw();
    void updateReleased();
};
 
#endif