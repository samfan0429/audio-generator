#ifndef BOX_H
#define BOX_H

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

# include "Note.h"
# include "Score.h"
# include "Player.h"

class Box
{
    private:
        std::shared_ptr<Player> player;
        std::shared_ptr<Score> score;

        void initVariables(std::string name);

    public:
        Box(std::string name);
        
        //Copy Constructors
        Box(const Box& a);
        Box &operator= (const Box& a);
        
        virtual ~Box();

        void update();
        void play();

        std::shared_ptr<Player> getPlayer();
        std::shared_ptr<Score> getScore();
};

#endif