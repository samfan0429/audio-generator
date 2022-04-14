# include "Mixer.h"

// Private functions
void Mixer::initvariables()
{
	this->setPosition(sf::Vector2f(3, 3));
	this->setSize(sf::Vector2f(1434, 400));
	this->setFillColor(sf::Color(192, 192, 192));
	this->setOutlineThickness(3);
	this->setOutlineColor(sf::Color(112, 128, 144));

	this->rotCount = 7;

	sf::Vector2f* center = new sf::Vector2f(50.0f, 50.0f);

	valDisplays.reserve(rotCount);
	setFont();

	ampRollers.reserve(rotCount);
	initAmpRollers(center);

}

void Mixer::initAmpRollers(sf::Vector2f* center)
{
	int x = 100, y = 100;

	for (unsigned int i = 0; i < rotCount; i++)
	{
		std::shared_ptr<sf::Text> tmp1 = std::make_shared<sf::Text>();
		tmp1->setFont(this->font);
		tmp1->setString("0");
		tmp1->setCharacterSize(24);
		tmp1->setFillColor(sf::Color::White);
		tmp1->setStyle(sf::Text::Bold);
		tmp1->setPosition(sf::Vector2f(x, y + 60));
		this->valDisplays.push_back(tmp1);

		std::shared_ptr<Roller> tmp = std::make_shared<Roller>(1.5f, tmp1, i);
		tmp->setOrigin(*center);
		tmp->setPosition(sf::Vector2f(x, y));
		this->ampRollers.push_back(tmp);
		x += 200;
	}
}

void Mixer::setFont()
{

	if (!this->font.loadFromFile("resources/font/arial.ttf"))//"C:/Users/USER/source/repos/Project3/Project3/resources/
	{
		std::cout << "Cannot Find Font in Mixer" << std::endl;
	}
}

// Public

// Constructor & Destructor
Mixer::Mixer(std::shared_ptr<SM> dat)
{
	this->dat = dat;
	this->initvariables();
	// this->draw();
}

Mixer::~Mixer()
{
	// std::cout << "Window deleted" << std::endl;
}

bool Mixer::updatePressed(sf::Vector2f mouse_pos)
{
	for (unsigned int i = 0; i < rotCount; i++)
	{
		if (this->ampRollers[i]->getGlobalBounds().contains(mouse_pos))
		{
			// std::cout << "I got clicked " << std::endl;
			this->dragged = this->ampRollers[i];
			return true;
		}
	}
	return false;
}

void Mixer::updateDragged(sf::Vector2f mouse_pos)
{
	this->dragged->update(mouse_pos);
}

void Mixer::updateReleased()
{
	this->dat->updateAmp(this->dragged->getID(), this->dragged->getCurr());
	this->dragged = nullptr;
}

void Mixer::draw()
{
	this->canvas->draw(*this);
	for (unsigned int i = 0; i < rotCount; i++)
	{
		this->canvas->draw(*ampRollers[i]);
		this->canvas->draw(*valDisplays[i]);
	}
}

void Mixer::setCanvas(sf::RenderWindow* window)
{
	this->canvas = window;
}

std::shared_ptr<Roller> Mixer::getDragged()
{
	return this->dragged;
}