#ifndef NOTE_H
#define NOTE_H

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


class Note
{
    private:
        double pitch;
        int dots, time, pace;

        void initVariables(int n, int time, int dots, int pace);

        void computeRailsback(int n);

    public:
        Note(int n, int time, int dots, int pace);
        
        //Copy Constructors
        Note(const Note& a);
        Note &operator= (const Note& a);
        
        virtual ~Note();

        void update();

        double getPitch();
        int getTime();
        int getDots();
        int getPace();
};

#endif