#ifndef SCORE_H
#define SCORE_H

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

class Score
{
    private:
        std::vector<std::shared_ptr<Note>> notes;
        int pace;

        void initVariables(std::string name);

        void computeRailsback(int n);

    public:
        Score(std::string name);
        
        //Copy Constructors
        Score(const Score& a);
        Score &operator= (const Score& a);
        
        virtual ~Score();

        void update();
        void play();

        std::vector<std::shared_ptr<Note>> getNotes();
        int getPace();
};

#endif