# include "Reader.h"

// Constructor && destructor
Reader::Reader(std::string name)
{
    this->initVariables(name);
}

Reader::~Reader()
{
    
}

// Copy Constructor
Reader::Reader(const Reader& a)
    : notes(a.notes), times(a.times)
{
}
 //Copy Operator
Reader& Reader::operator=(const Reader& a)
{
    *this = Reader(a);
    return *this;
}

// Private setups
void Reader::initVariables(std::string name)
{
    std::string tmp;
    std::ifstream file;
    file.open("notes/"+ name +".tsv");
    // std::cout << "Working so far" << std::endl;
    // int a = 0;

    while(std::getline(file, tmp))
    {
        // std::cout << tmp[0] << std::endl;
        std::istringstream iss(tmp);
        std::string note, duration;
        std::getline(iss, note, '\t');
        std::getline(iss, duration, '\t');

        this->times.push_back(stoi(duration));
        this->computeRailsback(stoi(note));

        // std::cout << note << '|' 
        //     << duration << std::endl;
    }

    for(int i=0; i<notes.size();i++)
    {
        std::cout << notes[i] << " with duration of " << times[i] << std::endl;
    }

}

void Reader::computeRailsback(int n)
{
    double expo = ((double)n-49.0)/12.0;
    double val = 440*pow(2.0,expo);
    this->notes.push_back(val);
}

// Public update due to input key
void Reader::update()
{

}