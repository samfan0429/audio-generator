#ifndef SM_H
#define SM_H

# include <iostream>
# include <vector>
# include <math.h>
class SM
{
private:
    float rbs[88];
    void initRb();

public:
    SM();

    unsigned int playCount = 0;
    float amps[7];
    bool pressed[88];

    void update(int n);

    bool isPlaying(int n);

    float getOutput(float phase);
    float getRbAt(int n);

};

#endif