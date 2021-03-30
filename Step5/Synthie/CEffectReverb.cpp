#include "stdafx.h"
#include "CEffectReverb.h"

CEffectReverb::CEffectReverb() {
	m_wrloc = 0;
    m_rdloc = 0;

	m_queuesize = 200000;
	m_queue.resize(m_queuesize);
	m_queue2.resize(m_queuesize);

	m_r = 1 - (0.01 / 2);
	m_co = (2 * m_r * cos(2 * 3.14 * 0.025) / (1 + m_r * m_r));
	m_a = (1 - m_r * m_r) * (acos(m_co));
}

CEffectReverb::~CEffectReverb() {

}

void CEffectReverb::Process(double* frameIn, double* frameOut) {
	//frameOut[0] = frameIn[0];
	//frameOut[1] = frameIn[1];

	double audio[2];
	audio[0] = frameIn[0];
	audio[1] = frameIn[1];

	//const int m_queuesize = 200000;
	//const double DELAY = 1.0;

	//std::vector<short> queue;
	//std::vector<short> queue2;
	//m_queue.resize(m_queuesize);
	//queue2.resize(m_queuesize);

	//int wrloc = 0;

	//double time = 0;





	m_wrloc = (m_wrloc + 2) % m_queuesize;
	m_queue[m_wrloc] = audio[0];
	m_queue[m_wrloc + 1] = audio[1];


	double audio_total_1 = 0;
	double audio_total_2 = 0;


	//audio_total_1 += queue[rdloc++] / 2;

	audio_total_1 = m_a * audio[0];
	audio_total_2 = m_a * audio[1];

	double weight = 2 * m_r * m_co;
	int delaylength = 1 * 2;
	int rdloc = (m_wrloc + m_queuesize - delaylength) % m_queuesize;
	int delaylength2 = 2 * 2;
	int rdloc2 = (m_wrloc + m_queuesize - delaylength2) % m_queuesize;

	double audio2_total_1 = (weight * m_queue2[rdloc++]) - ((m_r * m_r) * m_queue2[rdloc2++]);
	double audio2_total_2 = (weight * m_queue2[rdloc]) - ((m_r * m_r) * m_queue2[rdloc2]);


	//audio[0] = RangeBound(audio_total_1 + audio2_total_1);
	//audio[1] = RangeBound(audio_total_2 + audio2_total_2);

	//audio[0] = audio_total_1 + audio2_total_1;
	//audio[1] = audio_total_2 + audio2_total_2;


	//ProcessWriteFrame(audio);
	frameOut[0] = audio[0];
	frameOut[1] = audio[1];

	m_queue2[m_wrloc] = audio[0];
	m_queue2[m_wrloc + 1] = audio[1];

}

short CEffectReverb::RangeBound(double d)
{
	if (d > 32767) {
		return 32767;
	}
	if (d < -32768) {
		return -32768;
	}
	return short(d);
}