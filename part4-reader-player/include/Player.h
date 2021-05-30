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
# include "Note.h"

class Player
{
    private:
        std::vector<std::shared_ptr<Generator>> makers;
        int playing;
        sf::Sound ongoing;

        void initVariables(std::vector<std::shared_ptr<Note>> notes, int pace);

        void computeRailsback(int n);

    public:
        Player(std::vector<std::shared_ptr<Note>> notes, int pace);
        
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