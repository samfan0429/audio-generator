#ifndef PLAYER_H
#define PLAYER_H

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
 
# include <memory>
# include <iostream>

# include "Generator.h"

class Player
{
    private:
        std::vector<std::shared_ptr<Generator>> makers;
        int playing;
        sf::Sound ongoing;

        void initVariables(std::vector<double> notes, std::vector<int> times);

        void computeRailsback(int n);

    public:
        Player(std::vector<double> notes, std::vector<int> times);
        
        //Copy Constructors
        Player(const Player& a);
        Player &operator= (const Player& a);
        
        virtual ~Player();

        void update();
        void playSound();

        Generator getGenerator();
        sf::SoundBuffer getBuffer();
        sf::Sound getSound();
};

#endif