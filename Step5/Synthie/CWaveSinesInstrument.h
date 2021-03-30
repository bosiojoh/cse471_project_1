#pragma once
#include "Instrument.h"
#include "AR.h"
#include "CWaveSines.h"
#include "Notes.h"

class CWaveSinesInstrument :
    public CInstrument
{
public:
    CWaveSinesInstrument(void);
    ~CWaveSinesInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note);

    void SetDuration(double d) { m_ar.SetDuration(d); }
    //void SetFreq(double f) {}

    void SetFreq(double f) { m_sines.SetFreq(f); }

    void SetAmplitude(int i, double d) { m_sines.SetAmplitude(i, d); }

    void SetSample(double d) { m_sines.SetSample(d); }

    //void SetAttack(double value) { m_ar.SetAttack(value); }
    //void SetRelease(double value) { m_release = value; }
   // void SetRelease(double value) { m_release = value; }

private:
    CAR         m_ar;
    double  m_time;
    CWaveSines   m_sines;
};

