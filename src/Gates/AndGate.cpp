

#include "AndGate.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    AndGate::AndGate() : AComponent(3)
    {
    }

    AndGate::~AndGate()
    {
    }

    nts::Tristate AndGate::precompute(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::TRUE && b == nts::TRUE)
            return nts::TRUE;
        if ((a == nts::UNDEFINED && b == nts::TRUE) || (a == nts::TRUE && b == nts::UNDEFINED))
            return nts::UNDEFINED;
        if (a == nts::TRUE || b == nts::TRUE)
            return nts::FALSE;
        if (a == nts::FALSE || b == nts::FALSE)
            return nts::FALSE;
        return nts::UNDEFINED;
    }

    nts::Tristate AndGate::compute(std::size_t pin)
    {
        if (pin < 1 || pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);

        --pin;
        auto oComp = m_vPins[pin].m_pComponent;
        // ERROR
        if (!oComp && pin != 2)
            return nts::UNDEFINED;
        if (pin == 2) {
            m_vValues[0] = m_vPins[0].m_pComponent->compute(m_vPins[0].m_iPinId);
            m_vValues[1] = m_vPins[1].m_pComponent->compute(m_vPins[1].m_iPinId);
            m_vValues[pin] = precompute(m_vValues[0], m_vValues[1]);
            return m_vValues[pin];
        }
        return nts::UNDEFINED;
    }

    void AndGate::dump() const
    {
        std::cout << "   --- Type: AndGate" << std::endl;
        for (int i = 0; i < m_vPins.size(); ++i)
        {
            nts::Tristate eRetComp1 = UNDEFINED;
            if (m_vPins[i].m_pComponent)
                eRetComp1 = m_vPins[i].m_pComponent->compute(m_vPins[i].m_iPinId);
            std::cout << "      --- Pin " << (i + 1) << " --- " << std::endl;
            std::cout << "      --- Value: " << TristateToString(eRetComp1) << std::endl;
        }
    }
}