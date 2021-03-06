#ifndef MIXER_H
#define MIXER_H

# include <vector>
# include <memory>
# include <iostream>

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

# include "SM.h"
# include "Roller.h"

// Main Application
class Mixer : public sf::RectangleShape
{
private:
	std::vector<std::shared_ptr<Roller>> ampRollers;
	std::vector<std::shared_ptr<sf::Text>> valDisplays;
	// sf::Text freq;
	// sf::Text amp;

	std::shared_ptr<SM> dat;

	unsigned int rotCount;

	sf::Font font;

	sf::RenderWindow* canvas;
	std::shared_ptr<Roller> dragged;

	void initvariables();
	void setFont();
	void initAmpRollers(sf::Vector2f* center);

public:
	Mixer(std::shared_ptr<SM>);

	virtual ~Mixer();

	bool updatePressed(sf::Vector2f mouse_pos);

	void updateDragged(sf::Vector2f mouse_pos);
	void updateReleased();

	void draw();
	void setCanvas(sf::RenderWindow* window);

	std::shared_ptr<Roller> getDragged();
};

#endif