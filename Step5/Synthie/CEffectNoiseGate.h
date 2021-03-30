#pragma once
#include "Note.h"
#include <vector>

class CEffectNoiseGate
{
public:
	CEffectNoiseGate::CEffectNoiseGate();
	CEffectNoiseGate::~CEffectNoiseGate();
	void Process(double* frameIn, double* frameOut);

	void SetNote(CNote* note);
	void SetThreshold(double d) { m_threshold = d; }

	void SetMeasure(int i);

private:
	double m_threshold;
	std::vector<int> m_measures;
	std::vector<double> m_thresholds;

	int m_currentmeasure;
};

