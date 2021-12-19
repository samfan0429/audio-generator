# include "Roller.h"

// Private functions
void Roller::initvariables()
{
	if (!file.loadFromFile("resource/buttons/roller.png"))
	{
		std::cout << "Cannot Find" << std::endl;
	}
	else
	{
		// std::cout << "Found that roller" << std::endl;
		this->setTexture(file);
		this->curr = 0;
		// this->setOrigin(sf::Vector2f(50, 50));
	}
}

// Public

// Constructor & Destructor
Roller::Roller(float val, std::shared_ptr<sf::Text> display, unsigned int id)
{
	this->id = id;
	this->display = display;
	this->maxVal = val;
	this->initvariables();
}

Roller::~Roller()
{
	// std::cout << "Window deleted" << std::endl;
}

void Roller::fixCenter(sf::Vector2f pos)
{
	this->setOrigin(pos);
}

void Roller::update(sf::Vector2f mouse_pos)
{
	mouse_pos -= this->getPosition();

	double ang = atan2(mouse_pos.x, (-1)*mouse_pos.y)*180.0 / PI;

	this->curr = this->getRotation() / 360.0*maxVal;

	this->display->setString(std::to_string(this->curr));

	this->rotate(ang - this->getRotation());
}

float Roller::getCurr()
{
	return curr;
}

unsigned int Roller::getID()
{
	return id;
}