#pragma once
#include <vector>

class CEffectReverb
{
public:
	CEffectReverb::CEffectReverb();
	CEffectReverb::~CEffectReverb();
	void Process(double* frameIn, double* frameOut);
	short CEffectReverb::RangeBound(double d);

private:
	std::vector<double> m_queue;
	std::vector<double> m_queue2;
	int m_wrloc;
	int m_rdloc;

	int m_queuesize;
	double m_time;

	double m_r;
	double m_co;
	double m_a;
};

