#include "stdafx.h"
#include "CWaveSines.h"


#include <cmath>

CWaveSines::CWaveSines(void)
{
    for (int i = 0; i < 4; i++)
        m_amp[i] = 1;
}

CWaveSines::~CWaveSines(void)
{
}


void CWaveSines::Start()
{
    m_phase = 0;
}

bool CWaveSines::Generate()
{
    double sample = 0;
    if (m_sample == 1.0) {
        for (int i = 0; i < 4; i++)
        {
            sample += m_amp[i] * sin(m_phase * (i * 2 + 1));
        }
    }
    else if (m_sample == 2.0)
    {
        sample = sin(m_phase * (3 * 2 + 1));
    }
    else if (m_sample == 3.0)
    {
        sample = 0.5 * sin(m_phase * (2 * PI)) +  0.3* sin(m_phase * (4 * PI));
    }

    m_frame[1] = m_frame[0] = sample;
    m_phase += 2 * PI * m_freq * GetSamplePeriod();

    return true;
}
