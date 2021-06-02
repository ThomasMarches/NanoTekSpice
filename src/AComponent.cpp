
#include "AComponent.hpp"
#include "Exceptions/InvalidPin.hpp"
#include "Exceptions/SelfLink.hpp"

namespace nts
{
    AComponent::AComponent(int iMaxPins) : m_vPins(iMaxPins), m_vValues(iMaxPins)
    {
        m_iMaxPins = iMaxPins;
        for (auto& it : m_vValues)
            it = nts::UNDEFINED;
        m_bNeedToCompute = true;
    }

    AComponent::~AComponent()
    {
    }

    void AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
    {
        if (pin < 1 || pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);
        if (m_strName == other.getName() && pin == otherPin)
		    throw SelfLink(m_strName, pin);
        --pin;
        m_vPins[pin].m_iPinId = otherPin;
        m_vPins[pin].m_pComponent = &other;
    }

    Tristate AComponent::compute(std::size_t pin)
    {
        if (pin < 1 || pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);
        
        --pin;
        auto oComp = m_vPins[pin].m_pComponent;
        if (!oComp && m_bNeedToCompute) {
            // ERROR: No link
        } else {
            if (m_bNeedToCompute)
                m_vValues[pin] = oComp->compute(m_vPins[pin].m_iPinId);
        }
        return m_vValues[pin];
    }

    const Links& AComponent::getLink(PinID pin)
    {
        if (pin < 1 && pin > m_iMaxPins)
		    throw InvalidPin(m_strName, pin);
        --pin;
        return m_vPins[pin];
    }

    std::string AComponent::getName() const
    {
        return m_strName;
    }
    
    void AComponent::setName(const std::string& strName)
    {
        m_strName = strName;
    }

    void AComponent::setValue(nts::Tristate eValue)
    {
        m_vValues[0] = eValue;
    }
}