# include "Player.h"

// Constructor && destructor
Player::Player(std::vector<double> notes, std::vector<int> times)
{
    this->initVariables(notes, times);
}

Player::~Player()
{
    
}

// Copy Constructor
Player::Player(const Player& a)
    : makers(a.makers), playing(a.playing), ongoing(a.ongoing)
{
}
 //Copy Operator
Player& Player::operator=(const Player& a)
{
    *this = Player(a);
    return *this;
}

// Private setups
void Player::initVariables(std::vector<double> notes, std::vector<int> times)
{
    int l = notes.size();
    for(int i=0; i< l ; i++)
    {
        makers.push_back(std::make_shared<Generator>(notes[i], 0.9, "Sine",times[i]));
        if(!makers.empty()) // Debug
        {
            std::cout << "Working!!! at " << notes[i] << " w/ time " <<  times[i] << std::endl;
        }
    }
    playing = -1;
}

void Player::playSound()
{
    // makers[0]->play();
    // makers[1]->play();
    for(int i=0; i< makers.size();i++)
    {
        if(playing==-1)
        {
            playing = i;
            ongoing = makers[i]->getSound();
            ongoing.play();
        }
        else
        {
            while(ongoing.getStatus() == sf::Sound::Status::Playing)
            {
                continue;
            }
            ongoing = makers[i]->getSound();
            ongoing.play();
        }
    }
}

// Public update due to input key
void Player::update()
{

}