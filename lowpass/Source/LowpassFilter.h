//
//  LowpassFilter.h
//  lowpass
//
//  Created by Kanami Imamura on 2022/12/18.
//

#ifndef LowpassFilter_h
#define LowpassFilter_h

class LowpassFilter
{
private:
    float a0, a1, b0, b1;
    float in1, out1;
public:
    inline LowpassFilter();
    
    inline float Process(float in);
    inline void Lowpass(float freq=1000.0f, float samplerate=44100.0f);
};

LowpassFilter::LowpassFilter()
{
    a0 = 1.0f;
    a1 = 0.0f;
    b0 = 1.0f;
    b1 = 0.0f;
    
    in1 = 0.0f;
    out1 = 0.0f;
}

float LowpassFilter::Process(float in)
{
    float out = b0 / a0 * in + b1 / a0 * in1 - a1 / a0 * out1;
    in1 = in;
    out1 = out;
    
    return out;
}

void LowpassFilter::Lowpass(float freq, float samplerate)
{
    a0 = freq + 2;
    a1 = freq - 2;
    b0 = freq;
    b1 = freq;
}
#endif /* LowpassFilter_h */
