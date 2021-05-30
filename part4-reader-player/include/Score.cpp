# include "Score.h"

// Constructor && destructor
Score::Score(std::string name)
{
    this->initVariables(name);
}

Score::~Score()
{
    
}

// Copy Constructor
Score::Score(const Score& a)
    : notes(a.notes)
{
}
 //Copy Operator
Score& Score::operator=(const Score& a)
{
    *this = Score(a);
    return *this;
}

// Private setups
void Score::initVariables(std::string name)
{
    std::string tmp;
    std::ifstream file;
    file.open("notes/"+ name +".tsv");
    // std::cout << "Working so far" << std::endl;
    // int a = 0;

    getline(file, tmp);
    this->pace = stoi(tmp);
    std::cout << pace << std::endl;

    while(std::getline(file, tmp))
    {
        // std::cout << tmp[0] << std::endl;
        std::istringstream iss(tmp);
        std::string n, duration, dots;
        std::getline(iss, n, '\t');
        std::getline(iss, duration, '\t');
        std::getline(iss, dots, '\t');

        // int no = stoi(n);
        // int dur = stoi(duration);
        // int d = stoi(dots);
        // std::cout << no << " with duration of " << dur <<  " and " << d << " dots"<< std::endl;

        this->notes.push_back(std::make_shared<Note>(stoi(n), stoi(duration), stoi(dots)));
    }

    // for(int i=0; i<notes.size();i++)
    // {
    //     std::cout << notes[i] << " with duration of " << times[i] << std::endl;
    // }

}

// Public update due to input key
void Score::update()
{

}

std::vector<std::shared_ptr<Note>> Score::getNotes()
{
    return this->notes;
}

int Score::getPace()
{
    return this->pace;
}