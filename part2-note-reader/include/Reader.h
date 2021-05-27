#ifndef READER_H
#define READER_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
 
# include <memory>
# include <iostream>
# include <math.h>
# include <string>
# include <fstream>
# include <sstream>


class Reader
{
    private:
        std::vector<double> notes;
        std::vector<int> times;

        void initVariables(std::string name);

        void computeRailsback(int n);

    public:
        Reader(std::string name);
        
        //Copy Constructors
        Reader(const Reader& a);
        Reader &operator= (const Reader& a);
        
        virtual ~Reader();

        void update();
        void play();

        sf::SoundBuffer getBuffer();
        sf::Sound getSound();
};

#endif