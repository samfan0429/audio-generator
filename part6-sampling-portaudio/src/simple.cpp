# include "pa.h"
# include <math.h>
# include <iostream>

#define TWO_PI 6.2831853

double phase = 0, step = TWO_PI*440.0/44100.0;

void paFunc(const float* in, float* out, long frames, void* data){    

    for(int i = 0; i < frames; i++ ){
            phase += step;
            *out++ = 0.7*(sin(phase)+0.874*sin(3*phase)+0.684*sin(4*phase));
            // std::cout << *out << std::endl;
        }
}

int main() {
    // std::cout << "Working? " << std::endl;
    
    Pa a(paFunc, NULL);
    a.start(Pa::waitForKey);
    
    return 0;
}