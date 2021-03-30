#include "stdafx.h"
#include "CBassInstrument.h"
#include "Notes.h"

CBassInstrument::CBassInstrument(void)
{
    m_time = 0.0;
    m_attack = 0.05;
    m_decay = 0.07;
    m_release = 0.05;
}

CBassInstrument::~CBassInstrument(void)
{
}


void CBassInstrument::Start()
{
    m_wavePlayer.SetSampleRate(GetSampleRate());
    m_wavePlayer.Start();
    m_ar.SetSource(&m_wavePlayer);
}


void CBassInstrument::SetNote(CNote* note)
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

        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration(value.dblVal);
        }
        /*else if (name == "sample")
        {
            value.ChangeType(VT_R8);
            m_ba
        }*/
       /* else if (name == "note")
        {
            SetFreq(NoteToFrequency(value.bstrVal));
        }*/
        else if (name == "attack")
        {
            value.ChangeType(VT_R8);
            SetAttack(value.dblVal);
        }
        else if (name == "release")
        {
            value.ChangeType(VT_R8);
            SetRelease(value.dblVal);
        }
        else if (name == "decay")
        {
            value.ChangeType(VT_R8);
            SetDecay(value.dblVal);
        }
        else if (name == "rate") {
            value.ChangeType(VT_R8);
            m_wavePlayer.SetRate(value.dblVal);
        }
    }
}


bool CBassInstrument::Generate()
{
  /* bool valid = m_wavePlayer.Generate();

    m_frame[0] = m_wavePlayer.Frame(0);
    m_frame[1] = m_wavePlayer.Frame(0);

    m_time += GetSamplePeriod();

    // We return true until the time reaches the duration.
   return m_time < m_duration;

    //return valid; */

   
    
    //bool valid = m_wavePlayer.Generate();
    bool valid = m_wavePlayer.Pitch();

    // Attack
    if (m_time < m_attack)
    {
        m_frame[0] = m_wavePlayer.Frame(0) * (m_time / m_attack);
        m_frame[1] = m_wavePlayer.Frame(1) * (m_time / m_attack);
    }
    // Release
    else if (m_time > m_duration - m_release)
    {
        m_frame[0] = m_wavePlayer.Frame(0) * 0.50 * ((m_duration - m_time) / m_release);
        m_frame[1] = m_wavePlayer.Frame(1) * 0.50 * ((m_duration - m_time) / m_release);
    }
   // Decay to 50% volume
   else if (m_time < m_decay + m_attack && m_time > m_attack )
   {
        m_frame[0] = m_wavePlayer.Frame(0) * ((((m_attack + m_decay - m_time) / m_decay) / 2) + 0.50);
        m_frame[1] = m_wavePlayer.Frame(1) * ((((m_attack + m_decay - m_time) / m_decay) / 2) + 0.50);
   }
    // Sustain at 50% volume
    else
    {
        m_time;
        m_duration;
        m_frame[0] = m_wavePlayer.Frame(0) * 0.50;
        m_frame[1] = m_wavePlayer.Frame(1) * 0.50;
    }
    // Update time
    m_time += GetSamplePeriod();

    return m_time < m_duration;

    //m_frame[0] = m_wavePlayer.Frame(0);
    //m_frame[1] = m_frame[0];

    //return valid; 
}

