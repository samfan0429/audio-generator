# include "Keyboard.h"
# include <iostream>

// Private functions
void Keyboard::makeCtoB(float xi, float yi, int oct)
{
	float currX = xi, y = yi;

	int curr = oct * 12 + 4;

	// Create first three black ones
	for (int i = 0; i < 7; i++)
	{

		std::shared_ptr<Key> tmp = std::make_shared<Key>(curr);
		this->whites.push_back(tmp);
		tmp->setOutlineThickness(3);
		tmp->setOutlineColor(sf::Color::Black);
		tmp->setPosition(sf::Vector2f(currX, y));
		currX += (tmp->getSize().x + tmp->getOutlineThickness());
		if ((curr - 3) % 12 == 5)
		{
			curr++;
		}
		else
		{
			curr += 2;
		}
		if (i == 6)
		{
			currX = xi + tmp->getSize().x + tmp->getOutlineThickness();
		}
	}

	curr = oct * 12 + 5;

	for (int i = 0; i < 5; i++)
	{
		// std::cout << "Black called with " << curr << std::endl;
		std::shared_ptr<Key> tmp = std::make_shared<Key>(curr);
		this->blacks.push_back(tmp);
		tmp->setFillColor(sf::Color::Black);
		tmp->setOutlineThickness(3);
		tmp->setOutlineColor(sf::Color::Black);
		// tmp->setSize(sf::Vector2f(10.0, 100.0));
		tmp->setPosition(sf::Vector2f(currX - 6.5, y));
		// currX+=(tmp->getSize().x + tmp->getOutlineThickness());
		if ((curr - 3) % 12 == 4)
		{
			currX += (26.9) * 2;
			curr += 3;
		}
		else
		{
			currX += 26.9;
			curr += 2;
		}
	}

}

void Keyboard::initvariables()
{
	for (int i = 0; i < 88; i++)
	{
		this->playing[i] = 0;
	}

	countPlaying = 0;

	this->whites.reserve(52);
	this->blacks.reserve(36);
	float currX = 22, y = 450.0;

	this->whites.push_back(std::make_shared<Key>(1));
	this->whites[0]->setOutlineThickness(3);
	this->whites[0]->setOutlineColor(sf::Color::Black);
	this->whites[0]->setPosition(sf::Vector2f(currX, y));
	currX += (this->whites[0]->getSize().x + this->whites[0]->getOutlineThickness());

	this->whites.push_back(std::make_shared<Key>(3));
	this->whites[1]->setOutlineThickness(3);
	this->whites[1]->setOutlineColor(sf::Color::Black);
	this->whites[1]->setPosition(sf::Vector2f(currX, y));

	this->blacks.push_back(std::make_shared<Key>(2));
	this->blacks[0]->setFillColor(sf::Color::Black);
	this->blacks[0]->setOutlineThickness(3);
	this->blacks[0]->setOutlineColor(sf::Color::Black);
	// this->blacks[0]->setSize(sf::Vector2f(10.0, 100.0));
	this->blacks[0]->setPosition(sf::Vector2f(currX - 6.5, y));
	currX += (this->whites[0]->getSize().x + this->whites[0]->getOutlineThickness());

	for (int i = 0; i < 7; i++)
	{
		this->makeCtoB(currX, y, i);
		currX += (this->whites[0]->getSize().x + this->whites[0]->getOutlineThickness()) * 7;
	}

	this->whites.push_back(std::make_shared<Key>(88));
	this->whites[51]->setOutlineThickness(3);
	this->whites[51]->setOutlineColor(sf::Color::Black);
	this->whites[51]->setPosition(sf::Vector2f(currX, y));

	// currX+=27.6/2;
	// this->keys.push_back(std::make_shared<Key>(count++));
	// this->keys.push_back(std::make_shared<Key>(count++));

}

// Public

// Constructor & Destructor
Keyboard::Keyboard(std::shared_ptr<SM> dat)
{
	this->dat = dat;
	this->initvariables();
}

Keyboard::~Keyboard()
{
	// std::cout << "Window deleted" << std::endl;
}

void Keyboard::updatePressed(sf::Vector2f mouse_pos)
{
	// Look for black keys first.
	for (unsigned int i = 0; i < blacks.size(); i++)
	{
		if (this->blacks[i]->getGlobalBounds().contains(mouse_pos))
		{
			// std::cout << "I got clicked " << this->blacks[i]->getN() << std::endl;

			this->dat->update(this->blacks[i]->getN());

			if (!this->playing[this->blacks[i]->getN() - 1])
			{
				this->blacks[i]->setFillColor(sf::Color::Cyan);
				this->playing[this->blacks[i]->getN() - 1] = true;
				this->countPlaying++;
			}
			return;
		}
	}

	for (unsigned int i = 0; i < whites.size(); i++)
	{
		if (this->whites[i]->getGlobalBounds().contains(mouse_pos))
		{
			// std::cout << "I got clicked " << this->whites[i]->getN() << std::endl;
			this->dat->update(this->whites[i]->getN());

			if (!this->playing[this->whites[i]->getN() - 1])
			{
				this->whites[i]->setFillColor(sf::Color::Cyan);
				this->playing[this->whites[i]->getN() - 1] = true;
				this->countPlaying++;
			}
			return;
		}
	}
	return;
}

void Keyboard::updateReleased()
{
	for (unsigned int i = 0; i < blacks.size(); i++)
	{

		if (this->playing[this->blacks[i]->getN() - 1])
		{
			this->dat->update(this->blacks[i]->getN());
			// std::cout << "I got released " << this->blacks[i]->getN() << std::endl;
			this->blacks[i]->setFillColor(sf::Color::Black);
			this->playing[this->blacks[i]->getN() - 1] = false;
			this->countPlaying--;
			return;
		}
	}

	for (unsigned int i = 0; i < whites.size(); i++)
	{
		if (this->playing[this->whites[i]->getN() - 1])
		{
			this->dat->update(this->whites[i]->getN());
			// std::cout << "I got released " << this->whites[i]->getN() << std::endl;
			this->whites[i]->setFillColor(sf::Color::White);
			this->playing[this->whites[i]->getN() - 1] = false;
			this->countPlaying--;
			return;
		}
	}
}

void Keyboard::draw()
{
	// std::cout << "Working?" << std::endl;
	for (unsigned int i = 0; i < whites.size(); i++)
	{
		// std::cout << "Working?" << std::endl;
		this->canvas->draw(*(this->whites[i]));
	}

	for (unsigned int i = 0; i < blacks.size(); i++)
	{
		// std::cout << "Working?" << std::endl;
		this->canvas->draw(*(this->blacks[i]));
	}
}

void Keyboard::setCanvas(sf::RenderWindow* window)
{
	this->canvas = window;
}

std::vector<std::shared_ptr<Key>> Keyboard::getWhites()
{
	return this->whites;
}

std::vector<std::shared_ptr<Key>> Keyboard::getBlacks()
{
	return this->blacks;
}

bool Keyboard::getPlaying()
{
	if (countPlaying == 0) return false;

	return true;
}