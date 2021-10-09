# include "pa.h"
# include <math.h>
# include <iostream>

#define TWO_PI 6.2831853

double phase = 0, step = TWO_PI*440.0/44100.0;

void paFunc(const float* in, float* out, long frames, void* data){    

    for(int i = 0; i < frames; i++ ){
            phase += step;
            *out++ = sin(phase)+1.869*sin(2*phase)+0.042*sin(3*phase)+0.022*sin(4*phase);
            // std::cout << *out << std::endl;
        }
}

int main() {
    std::cout << "Working? " << std::endl;
    
    Pa a(paFunc, NULL);
    a.start(Pa::waitForKey);
    
    return 0;
}