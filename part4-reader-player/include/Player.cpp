# include "Player.h"

// Constructor && destructor
Player::Player(std::vector<std::shared_ptr<Note>> notes)
{
    this->initVariables(notes);
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
void Player::initVariables(std::vector<std::shared_ptr<Note>> notes)
{
    int l = notes.size();
    for(int i=0; i< l ; i++)
    {
        if(notes[i]->getPitch()<0)
        {
            makers.push_back(std::make_shared<Generator>(notes[i]->getPitch(), 0, "Sine", notes[i]->getTime(), notes[i]->getDots(), notes[i]->getPace()));
        }
        else
        {
            makers.push_back(std::make_shared<Generator>(notes[i]->getPitch(), 0.9, "Sine", notes[i]->getTime(), notes[i]->getDots(), notes[i]->getPace()));
        }
        
        // if(!makers.empty()) // Debug
        // {
        //     std::cout << "Working!!! at " << notes[i]->getPitch() << " w/ time " << notes[i]->getTime()<< " with extra notes of " << notes[i]->getDots() << "th" 
        //     << " at pace of " << notes[i]-> getPace() << std::endl;
        // }
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