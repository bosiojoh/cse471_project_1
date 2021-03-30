#pragma once
#include "Instrument.h"
#include "CWavePlayer.h"
#include "AR.h"

class CBassInstrument :
    public CInstrument
{
public:
    CBassInstrument(void);
    ~CBassInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note);

    CWavePlayer* GetPlayer() { return &m_wavePlayer; }

    //void SetFreq(double f) { m_wavePlayer.SetFreq(f); }
    //void SetAmplitude(int i, double d) { m_sines.SetAmplitude(i, d); }

    void SetDuration(double d) { m_duration = d; }

    void SetAttack(double d) { m_attack = d; }
    void SetRelease(double d) { m_release = d; }
    void SetDecay(double d) { m_decay = d; }
    void SetRate(double d) {  m_wavePlayer.SetRate(d); }

private:
    CWavePlayer m_wavePlayer;
    CAR m_ar;
    double m_time;
    double m_duration;

    double m_attack;
    double m_decay;
    double m_release;
};

