#pragma once
#include "AudioNode.h"
class CWaveSines :
    public CAudioNode
{
public:
    CWaveSines(void);
    ~CWaveSines(void);

public:
    virtual void Start();
    virtual bool Generate();

    void SetFreq(double f) { m_freq = f; }
    void SetAmplitude(int i, double a) { m_amp[i] = a; }
    void SetSample(double d) { m_sample = d; }

private:
    double m_freq;
    double m_phase;
    double m_amp[4];
    double m_sample;
};

