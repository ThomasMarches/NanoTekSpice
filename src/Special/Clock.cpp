
#include "Clock.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    Clock::Clock() : Input()
    {
        m_bNeedToCompute = false;
    }
    
    Clock::~Clock()
    {
    }
    
    void Clock::dump() const
    {
        std::cout << getName() << ": " << TristateToString(m_vValues[0]) << std::endl;
    }

    Tristate Clock::compute(PinID pin)
    {
        if (pin < 1 && pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);
        
        --pin;
        if (m_vValues[pin] == TRUE)
            m_vValues[pin] = FALSE;
        else if (m_vValues[pin] == FALSE)
            m_vValues[pin] = TRUE;
        else
            m_vValues[pin] = UNDEFINED;
        return m_vValues[pin];
    }
}