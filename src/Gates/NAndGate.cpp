

#include "NAndGate.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    NAndGate::NAndGate() : AComponent(3)
    {
    }

    NAndGate::~NAndGate()
    {
    }

    nts::Tristate NAndGate::precompute(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::TRUE && b == nts::TRUE)
            return nts::FALSE;
        if (a == nts::FALSE && b == nts::FALSE)
            return nts::TRUE;
        if (a == nts::UNDEFINED && b == nts::UNDEFINED)
            return nts::UNDEFINED;
        if ((a == nts::FALSE && b == nts::TRUE) || (a == nts::TRUE && b == nts::FALSE))
            return nts::TRUE;
        if ((a == nts::UNDEFINED && b == nts::FALSE) || (a == nts::FALSE && b == nts::UNDEFINED))
            return nts::TRUE;
        if ((a == nts::UNDEFINED && b == nts::TRUE) || (a == nts::TRUE && b == nts::UNDEFINED))
            return nts::UNDEFINED;
        return nts::UNDEFINED;
    }

    nts::Tristate NAndGate::compute(std::size_t pin)
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

    void NAndGate::dump() const
    {
    }
}