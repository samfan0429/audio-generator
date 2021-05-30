# include "Note.h"

// Constructor && destructor
Note::Note(int n, int time, int dots)
{
    this->initVariables(n, time, dots);
}

Note::~Note()
{
    
}

// Copy Constructor
Note::Note(const Note& a)
    : pitch(a.pitch),time(a.time), dots(a.dots)
{
}
 //Copy Operator
Note& Note::operator=(const Note& a)
{
    *this = Note(a);
    return *this;
}

// Private setups
void Note::initVariables(int n, int time, int dots)
{
    computeRailsback(n);
    this->time = time;
    this->dots = dots;
    std::cout << this->pitch << " with duration of " << this->time <<  " and " << this->dots << " dots"<< std::endl;
}

void Note::computeRailsback(int n)
{
    if(n==-1)
    {
        this->pitch = -5.0;
        return;
    }
    double expo = ((double)n-49.0)/12.0;
    double val = 440.0*pow(2.0,expo);
    this->pitch = val;
}

// Public update due to input key
void Note::update()
{

}

double Note::getPitch()
{
    return this->pitch;
}

int Note::getTime()
{
    return this->time;
}

int Note::getDots()
{
    return this->dots;
}