# include <iostream>
// # include <Windows.h>
# include <memory>
# include <math.h>

# include <SFML/Graphics.hpp>
// # include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>

# include "Space.h"
# include "pa.h"

#define TWO_PI 6.2831853

double phase = 0, step = TWO_PI*440.0/44100.0;

void paFunc(const float* in, float* out, long frames, void* data){    

    for(int i = 0; i < frames; i++ ){
            phase += step;
            *out++ = sin(phase);
        }
}

int main()
{
    // create the window
    bool play = false, stop = false;
    Pa player(paFunc, NULL);
    std::unique_ptr<Space> window = std::make_unique<Space>();

    while (window->running())
    {
        // handle events
        window->update(); 

        play = window->getPlaying();
        stop = window->getStopped();
    
        if(play && !stop)
        {
            // std::cout << "playing" << std::endl;
            player.start();
        }
        else if(play && stop)
        {
            // std::cout << "stopped" << std::endl;
            player.stop();
        }

        window->render();
    }


    return 0;
}