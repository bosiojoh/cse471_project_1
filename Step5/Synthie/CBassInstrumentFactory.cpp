#include "stdafx.h"
#include "CBassInstrumentFactory.h"
#include "audio/DirSoundSource.h" 
#include <cmath>

CBassInstrumentFactory::CBassInstrumentFactory(void)
{
    for (double time = 0; time < 2; time += 1. / 44100.)
    {
        m_bass.push_back(short(3267 * sin(2 * 3.1415 * 1000 * time)));
    }
}

CBassInstrumentFactory::~CBassInstrumentFactory(void)
{
}


CBassInstrument* CBassInstrumentFactory::CreateInstrument()
{
    CBassInstrument* instrument = new CBassInstrument();
    instrument->GetPlayer()->SetSamples(&m_bass[0], (int)m_bass.size());

    return instrument;
}

void CBassInstrumentFactory::SetNote(CNote* note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

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

        if (name == "sample")
        {
            value.ChangeType(VT_R8);
            if (value.dblVal == 1.0) {
                LoadFile("jp_deep_bass_01.wav");
            }
            else if (value.dblVal == 2.0) {
                LoadFile("jp_deep_bass_02.wav");
            }
            else if (value.dblVal == 3.0) {
                LoadFile("jp_deep_bass_03.wav");
            }
            else if (value.dblVal == 4.0) {
                LoadFile("jp_deep_bass_06.wav");
            }
            else if (value.dblVal == 5.0) {
                LoadFile("jp_deep_bass_08.wav");
            }
            //this->LoadFile()
            //m_amps[0] = value.dblVal;
        }
       /* else if (name == "attack") {
            value.ChangeType(VT_R8);
            SetAttack(value.dblVal);
        } */

       /* if (name == "a1")
        {
            value.ChangeType(VT_R8);
            m_amps[0] = value.dblVal;
        }
        else if (name == "a3")
        {
            value.ChangeType(VT_R8);
            m_amps[1] = value.dblVal;
        }
        else if (name == "a5")
        {
            value.ChangeType(VT_R8);
            m_amps[2] = value.dblVal;
        }
        else if (name == "a7")
        {
            value.ChangeType(VT_R8);
            m_amps[3] = value.dblVal;
        }*/

    }

}

bool CBassInstrumentFactory::LoadFile(const char* filename)
{
    m_bass.clear();

    CDirSoundSource m_file;
    if (!m_file.Open(filename))
    {
        CString msg = L"Unable to open audio file: ";
        msg += filename;
        AfxMessageBox(msg);
        return false;
    }

    for (int i = 0; i < m_file.NumSampleFrames(); i++)
    {
        short frame[2];
        m_file.ReadFrame(frame);
        m_bass.push_back(frame[0]);
    }

    m_file.Close();
    return true;
}
