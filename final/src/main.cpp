# include <iostream>
# include <memory>

# include <SFML/graphics.hpp>
# include <SFML/network.hpp>
# include <SFML/window.hpp>
# include <SFML/system.hpp>

# include "Space.h"
# include "Pa.h"
# include "SM.h"
# include "math.h"

#define TWO_PI 6.2831853

float phase = 0, step = TWO_PI/ 44100.00;

void paFunc(const float* in, float* out, long frames, void* data) {

	SM* tmp = reinterpret_cast<SM*>(data);
	//std::cout << "works" << std::endl;
	for (int i = 0; i < frames; i++) {
		phase += step;
		//*out++ = sin(phase)*0.5;
		//std::cout << "works" << std::endl;
		*out++ = tmp->getOutput(phase);
	}
}

int main()
{
	// create the window
	bool play = false, playing = false;
	//std::shared_ptr<SM> dat = std::make_shared<SM>();
	SM* dat = new SM();
	Pa player(paFunc, dat);
	std::unique_ptr<Space> window = std::make_unique<Space>(dat);

	while (window->running())
	{
		// handle events
		window->update();

		play = window->getPlaying();

		if (play&!playing)
		{
			// std::cout << "playing" << std::endl;
			playing = true;
			player.start();
		}
		else if (!play&playing)
		{
			//std::cout << "stopped" << std::endl;
			playing = false;
			player.stop();
		}

		window->render();
	}


	return 0;
}