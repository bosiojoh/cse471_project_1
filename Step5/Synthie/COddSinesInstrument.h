#pragma once
#include "Instrument.h"
#include "AR.h"
#include "COddSines.h"
#include "Notes.h"
//#include "SineWave.h"

class COddSinesInstrument :
    public CInstrument
{
public:
    COddSinesInstrument(void);
    ~COddSinesInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note);

    void SetDuration(double d) { m_ar.SetDuration(d); }
    //void SetFreq(double f) {}

    void SetFreq(double f) { m_sines.SetFreq(f); }

    void SetAmplitude(int i, double d) { m_sines.SetAmplitude(i, d); }

    //void SetAttack(double value) { m_ar.SetAttack(value); }
    //void SetRelease(double value) { m_release = value; }
   // void SetRelease(double value) { m_release = value; }

private:
    CAR         m_ar;
    double  m_time;
    COddSines   m_sines;
};

