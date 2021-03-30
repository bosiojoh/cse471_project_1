#pragma once
#include <vector>
#include "CBassInstrument.h"
#include "Note.h"

class CBassInstrumentFactory
{
public:
    CBassInstrumentFactory(void);
    ~CBassInstrumentFactory(void);

    void SetNote(CNote* note);
    CBassInstrument* CreateInstrument();
    bool LoadFile(const char* filename);

private:
    std::vector<short> m_bass;
    //std::vector<short> m_bass2;
    //std::vector<short> m_bass3;
    //std::vector<short> m_bass4;
    //std::vector<short> m_bass4;
};

