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
# include "SM.h"

#define TWO_PI 6.2831853

double phase = 0, step = TWO_PI/44100.00;

// step = TWO_PI*440/44100.0;

void paFunc(const float* in, float* out, long frames, void* data){    

    SM* tmp = reinterpret_cast<SM*>(data);
    for(int i = 0; i < frames; i++ ){
            phase += step;
            *out++ = sin(tmp->freqs[0]*phase)+\
            tmp->amps[0]*sin(tmp->freqs[0]*2*phase)+\
            tmp->amps[1]*sin(tmp->freqs[0]*3*phase)+\
            tmp->amps[2]*sin(tmp->freqs[0]*4*phase)+\
            tmp->amps[3]*sin(tmp->freqs[0]*5*phase)+\
            tmp->amps[4]*sin(tmp->freqs[0]*6*phase)+\
            tmp->amps[5]*sin(tmp->freqs[0]*7*phase)+\
            tmp->amps[6]*sin(tmp->freqs[0]*8*phase);
        }
}

int main()
{
    // create the window
    bool play = false, stop = false;
    std::shared_ptr<SM> dat = std::make_shared<SM>();
    Pa player(paFunc, dat);
    std::unique_ptr<Space> window = std::make_unique<Space>(dat);

    while (window->running())
    {
        // handle events
        window->update(); 

        play = window->getPlaying();
        // stop = window->getStopped();
    
        if(play)
        {
            // std::cout << "playing" << std::endl;
            player.start();
        }
        else
        {
            // std::cout << "stopped" << std::endl;
            player.stop();
        }

        window->render();
    }


    return 0;
}