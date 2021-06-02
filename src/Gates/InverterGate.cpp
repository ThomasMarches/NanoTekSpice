

#include "InverterGate.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    InverterGate::InverterGate() : AComponent(2)
    {
    }

    InverterGate::~InverterGate()
    {
    }

    nts::Tristate InverterGate::precompute(nts::Tristate a)
    {
        if (a == nts::TRUE)
            return nts::FALSE;
        if (a == nts::FALSE)
            return nts::TRUE;
        return nts::UNDEFINED;
    }

    nts::Tristate InverterGate::compute(std::size_t pin)
    {
        if (pin < 1 || pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);

        --pin;
        auto oComp = m_vPins[pin].m_pComponent;
        // ERROR
        if (!oComp)
            return nts::UNDEFINED;
        m_vValues[0] = m_vPins[0].m_pComponent->compute(m_vPins[0].m_iPinId);
        m_vValues[pin] = precompute(m_vValues[0]);
        return m_vValues[pin];
    }

    void InverterGate::dump() const
    {
    }
}