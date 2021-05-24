# include "Spring.h"

// Constructor && destructor
Spring::Spring(int x, int y)
{
    this->initVariables(x,y);
}

Spring::~Spring()
{
    
}

// Copy Constructor
Spring::Spring(const Spring& a)
    : obj(a.obj)
{
}
 //Copy operator
Spring& Spring::operator=(const Spring& a)
{
    *this = Spring(a);
    return *this;
}

// Private setups

void Spring::initVariables(int x,int y)
{
    this->obj = new sf::RectangleShape(sf::Vector2f(x,y));
    this->obj->setPosition(200,200);
}

// Public update due to input key
void Spring::update()
{

}

sf::RectangleShape Spring::getObj(){
    return *(this->obj);
}