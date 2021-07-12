# include "Button.h"

// Private functions
void Button::initvariables(sf::Vector2f size, sf::Vector2f position)
{
    clicked = false;
    this->setRectangle(size, position);
    this->setText(position);
}

void Button::setRectangle(sf::Vector2f size, sf::Vector2f position)
{
    this->tile = std::make_shared<sf::RectangleShape>();
    this->tile->setPosition(position);
    this->tile->setSize(size);
    this->tile->setFillColor(sf::Color(192,192,192));
    this->tile->setOutlineThickness(3);
    this->tile->setOutlineColor(sf::Color(112,128,144));
}

void Button::setText(sf::Vector2f position)
{

    if(!this->font.loadFromFile("resource/font/arial.ttf"))
    {
        std::cout << "Cannot Find" << std::endl;
    }
    else
    {
        this->text = std::make_shared<sf::Text>();
        this->text->setFont(this->font);

        this->text->setString(this->name);

        this->text->setCharacterSize(24);

        this->text->setFillColor(sf::Color::White);

        this->text->setStyle(sf::Text::Bold);

        this->text->setPosition(sf::Vector2f(position.x+3, position.y+5));
    }
}

// Public

// Constructor & Destructor
Button::Button(std::string name, sf::Vector2f size, sf::Vector2f position)
{   
    this->name = name;
    this->initvariables(size, position);
}

Button::~Button()
{
    // std::cout << "Window deleted" << std::endl;
}

bool Button::isClicked(sf::Vector2f mouse_pos)
{
    if(this->tile->getGlobalBounds().contains(mouse_pos))
    {
        clicked = true;
        this->tile->setFillColor(sf::Color::Black);
        return true;
    }
    return false;
}

void Button::updateReleased()
{
    clicked = false;
    this->tile->setFillColor(sf::Color(192,192,192));
}

void Button::setCanvas(sf::RenderWindow* window)
{
    this->canvas = window;
}

void Button::draw()
{   
    this->canvas->draw(*(this->tile));
    this->canvas->draw(*(this->text));
}

bool Button::getClicked()
{
    return this->clicked;
}