//
//  lowpassfilter.h
//  lowpass
//
//  Created by Kanami Imamura on 2022/12/18.
//

#ifndef lowpassfilter_h
#define lowpassfilter_h

class LowpassFilter
{
private:
    float a0, a1, b0, b1;
    float in1;
    float out1;
public:
    inline LowpassFilter();
    
    inline float Process(float in);
    inline void Lowpass (float freq, float q , float samplerate = 44100.0f);

}

LowpassFilter::LowpassFilter()
{
    f0 = 1000.0f;
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

#endif /* lowpassfilter_h */
