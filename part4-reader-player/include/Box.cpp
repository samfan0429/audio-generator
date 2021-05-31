# include "Box.h"

// Constructor && destructor
Box::Box(std::string name)
{
    this->initVariables(name);
}

Box::~Box()
{
    
}

// Copy Constructor
Box::Box(const Box& a)
    : player(a.player), score(a.score)
{
}
 //Copy Operator
Box& Box::operator=(const Box& a)
{
    *this = Box(a);
    return *this;
}

// Private setups
void Box::initVariables(std::string name)
{
    this->score = std::make_shared<Score>(name);
    this->player = std::make_shared<Player>(this->score->getNotes());
}

// Public update due to input key
void Box::update()
{

}

void Box::play()
{
    this->player->playSound();
}

std::shared_ptr<Player> Box::getPlayer()
{
    return this->player;
}

std::shared_ptr<Score> Box::getScore()
{
    return this->score;
}