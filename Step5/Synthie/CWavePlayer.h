#pragma once
#include "AudioNode.h"

class CWavePlayer :
    public CAudioNode
{
public:
    CWavePlayer(void);
    ~CWavePlayer(void);

public:
    virtual void Start();
    virtual bool Generate();

    void SetSamples(short* s, int n) { m_samples = s; m_numsamples = n; }

    bool Pitch();
    void SetRate(double d) { m_rate = d; }

private:
    short* m_samples;
    int    m_numsamples;
    int    m_position;

    double m_rate;
    double m_position_double;
};

