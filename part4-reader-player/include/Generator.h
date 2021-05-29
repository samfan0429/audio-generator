#ifndef GENERATOR_H
#define GENERATOR_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <string>
# include <memory>
# include <iostream>

#include <math.h>
#include <string>
#define TWOPI 6.283185307

class Generator
{
    private:
        std::vector<sf::Int16> sample;
        sf::Sound soundPlayer;
        sf::SoundBuffer buffer;

        void initVariables(double freq, double amp, std::string type, double time, int dots, double rate);

    public:
        Generator(double freq, double amp, std::string type, double time, int dots, double rate);
        
        //Copy Constructors
        Generator(const Generator& a);
        Generator &operator= (const Generator& a);
        
        virtual ~Generator();

        void makeSineWave(int time, double freq, double amp);
        void makeSquare(int time, double freq, double amp);
        void makeNoise(double amp);

        void update();
        void play();

        std::vector<sf::Int16> getSample();
        sf::SoundBuffer getBuffer();
        sf::Sound getSound();
};

#endif