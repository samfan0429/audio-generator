#ifndef ROLLER_H
#define ROLLER_H

# include <vector>
# include <memory>
# include <iostream>
# include <math.h> 

#define PI 3.14159265

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>


// Main Application
class Roller : public sf::Sprite
{
private:
	unsigned int id;
	sf::Texture file;
	std::shared_ptr<sf::Text> display;

	float curr, maxVal;

	void initvariables();

public:
	Roller(float, std::shared_ptr<sf::Text>, unsigned int);

	virtual ~Roller();

	void changeFormer();

	void fixCenter(sf::Vector2f pos);

	void update(sf::Vector2f mouse_pos);

	float getCurr();

	unsigned int getID();
};

#endif