#include "StdAfx.h"
#include "CWavePlayer.h"

#include <math.h>

CWavePlayer::CWavePlayer(void)
{
    m_samples = NULL;
    m_numsamples = 0;
    m_rate = 1.0;
    m_position_double = 0.0;
}

CWavePlayer::~CWavePlayer(void)
{
}

void CWavePlayer::Start()
{
    m_position = 0;
}

bool CWavePlayer::Generate()
{
    if (m_position < m_numsamples)
    {
        m_frame[0] = m_samples[m_position++] / 32768.0;
        m_frame[1] = m_frame[0];
        return true;
    }
    else
    {
        m_frame[1] = m_frame[0] = 0;
        return false;
    }
}

bool CWavePlayer::Pitch()
{
    if (m_position_double < m_numsamples)
    {
       // m_frame[0] = m_samples[m_position] / 32768.0;


        //short position = m_position;
        m_position_double += m_rate;

        double inbetween = fmod(m_position_double, 1);
        short samp = (1.0 - inbetween) * m_samples[int(m_position_double)] + inbetween * m_samples[int(m_position_double) + 1];
    
        m_frame[0] = samp / 32768.0;
        m_frame[1] = m_frame[0];
        return true;
    }
    else
    {
        m_frame[1] = m_frame[0] = 0;
        return false;
    }
}