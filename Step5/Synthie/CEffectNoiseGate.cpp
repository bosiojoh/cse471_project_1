#include "stdafx.h"
#include "CEffectNoiseGate.h"
#include <algorithm>

CEffectNoiseGate::CEffectNoiseGate() {
    m_threshold = 0.0;
}

CEffectNoiseGate::~CEffectNoiseGate() {

}

void CEffectNoiseGate::SetNote(CNote* note) {
    // Get a list of all attribute nodes and the
        // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    //m_measures.push_back(note->Measure() + 1);

    // Loop over the list of attributes
    for (int i = 0; i < len; i++)
    {
        // Get attribute i
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the name of the attribute
        CComBSTR name;
        attrib->get_nodeName(&name);

        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "threshold")
        {
            value.ChangeType(VT_R8);
            //m_thresholds.push_back(value.dblVal);
            m_threshold = value.dblVal;
        }
       
    }
}

void CEffectNoiseGate::Process(double* frameIn, double* frameOut) {
    auto it = std::find(m_measures.begin(), m_measures.end(), m_currentmeasure);
    if (it == m_measures.end()) {
        
    }

	if (frameIn[0] < m_threshold) {
		frameOut[0] = 0;
		frameOut[1] = 0;
	}
	else {
		frameOut[0] = frameIn[0];
		frameOut[1] = frameIn[1];
	}
}

void CEffectNoiseGate::SetMeasure(int i) {
    m_currentmeasure = i;
    auto it = std::find(m_measures.begin(), m_measures.end(), m_currentmeasure);
    if (it == m_measures.end()) {
        m_threshold = 0.0;
    }
    else {
        int index = it - m_measures.begin();
        m_threshold = m_thresholds[index];
    }

}