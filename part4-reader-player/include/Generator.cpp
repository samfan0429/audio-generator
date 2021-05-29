# include "Generator.h"

// Constructor && destructor
Generator::Generator(double freq, double amp, std::string type, double time, int dots, double rate)
{
    // std::cout << "WORKING?" << std::endl;
    this->initVariables(freq, amp, type, time, dots, rate);
}

Generator::~Generator()
{
    
}

// Copy Constructor
Generator::Generator(const Generator& a)
    : sample(a.sample), soundPlayer(a.soundPlayer), buffer(a.buffer)
{
}
 //Copy Operator
Generator& Generator::operator=(const Generator& a)
{
    *this = Generator(a);
    return *this;
}

// Private sampleups

void Generator::initVariables(double freq, double amp, std::string type, double time, int dots, double rate)
{
    // std::cout << "It fucking works wtf" << std::endl;
    double t = 44100.0*4.0/time*rate;
    if(dots > 0)
    {
        t+= 44100.0*4.0/(time*pow(2,dots))*rate;
    }
    int duration = (int)t;
    // std::cout << "It fucking works wtf" << std::endl;
    for(int i=0; i<duration; i++)
    {
        // std::cout << "It fucking works wtf" << std::endl;
        if(type == "Sine")
        {
            this->makeSineWave(i, freq, amp);
        } else if (type == "Square")
        {
            this->makeSquare(i, freq, amp);
        } else
        {
            this->makeNoise(amp);
        }
    }

    this->buffer.loadFromSamples(&(this->sample[0]), this->sample.size(), 1, 44100);
    this->soundPlayer.setBuffer(this->buffer);
}

// sample SineWaves
void Generator::makeSineWave(int time, double freq, double amp)
{
    short result;
    double tpc = 44100 / freq; // ticks per cycle
    double cycles = time / tpc;
    double rad = TWOPI * cycles;
    short amplitude = 32767 * amp;
    result = amplitude * sin(rad);
    // if(time%1000 == 0)
    // {
    //     std::cout << "It is adding " << time << std::endl;
    // }
    this->sample.push_back(result);
}

// sample Sine Square waves
void Generator::makeSquare(int time, double freq, double amp)
{
    short result = 0;
    int tpc = 44100 / freq; // ticks per cycle
    int cyclepart = int(time) % tpc;
    int halfcycle = tpc / 2;
    short amplitude = 32767 * amp;
    if (cyclepart < halfcycle) {
        result = amplitude;
    }
    this->sample.push_back(result);
}

// Make Noise
void Generator::makeNoise(double amp)
{
    short result = 0;
    short amplitude = 32767 * amp;
    result = rand() % amplitude;
    this->sample.push_back(result);
}

// Public update due to input key
void Generator::update()
{

}

void Generator::play()
{
    this->soundPlayer.play();
}

std::vector<sf::Int16> Generator::getSample()
{
    // std::cout << "Works?" << std::endl;
    return this->sample;
}

sf::SoundBuffer Generator::getBuffer()
{
    return (this->buffer);
}

sf::Sound Generator::getSound()
{
    return this->soundPlayer;
}