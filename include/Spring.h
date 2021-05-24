#ifndef SPRING_H
#define SPRING_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <string>
# include <memory>
# include <iostream>

class Spring
{
    private:
        sf::RectangleShape* obj;

        void initVariables(int x,int y);

    public:
        Spring(int x,int y);
        
        //Copy Constructors
        Spring(const Spring& a);
        Spring &operator= (const Spring& a);
        
        virtual ~Spring();

        void update();

        sf::RectangleShape getObj();
};

#endif