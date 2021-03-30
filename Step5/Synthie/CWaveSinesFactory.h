#pragma once
#include "CWaveSinesInstrument.h"

class CWaveSinesFactory
{
public:
	CWaveSinesFactory::CWaveSinesFactory();
	CWaveSinesInstrument* CreateInstrument();
	void SetNote(CNote* note);

private:
	double m_amps[4];
	double m_sample;
};

