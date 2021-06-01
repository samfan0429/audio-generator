#ifndef KEY_H
#define KEY_H

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
class Key: public sf::RectangleShape
{
private:
    int n;
    
    void initvariables(int n);
    
public:
    Key(int n);

    virtual ~Key();

    void update();

    int getN();
};
 
#endif