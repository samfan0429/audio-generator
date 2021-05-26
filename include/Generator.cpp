# include "Generator.h"

// Constructor && destructor
Generator::Generator(double freq, double amp, std::string type)
{
    this->initVariables(freq, amp, type);
}

Generator::~Generator()
{
    
}

// Copy Constructor
Generator::Generator(const Generator& a)
    : buffer(a.buffer), sample(a.sample), soundPlayer(a.soundPlayer), freq(a.freq), amp(a.amp)
{
}
 //Copy Operator
Generator& Generator::operator=(const Generator& a)
{
    *this = Generator(a);
    return *this;
}

// Private sampleups

void Generator::initVariables(double freq, double amp, std::string type)
{
    // std::cout << "It fucking works wtf" << std::endl;
    this->freq = freq;
    this->amp = amp;
    for(int i=0; i<44100; i++)
    {
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

    // for(int i=0; i<44100; i++)
    // {
    //     if(i%1000 == 0)
    //     {
    //         std::cout << "Here: " << sample[i] << std::endl;
    //     }
    // }

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

sf::SoundBuffer Generator::getBuffer()
{
    return (this->buffer);
}

sf::Sound Generator::getSound()
{
    return this->soundPlayer;
}