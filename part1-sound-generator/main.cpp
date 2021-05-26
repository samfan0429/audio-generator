# include <iostream>
// # include <Windows.h>
# include <memory>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include "Space.h"

int main()
{
    // create the window
    std::unique_ptr<Space> window = std::make_unique<Space>();

    while (window->running())
    {
        // handle events
        window->update();        


        window->render();
    }


    return 0;
}