
#include <utility>
#include "AComponent.hpp"
#include "Exceptions/InvalidPin.hpp"

#if !defined(_FOUR_GATES_HPP_)
#define _FOUR_GATES_HPP_

namespace nts
{
    template<typename T>
    class FourGates : public AComponent
    {
    public:
        FourGates() : AComponent(14)
        {
            m_vLinks[0] = {0, 1}; // Input Gate 1
			m_vLinks[1] = {0, 2}; // Input Gate 1
			m_vLinks[2] = {0, 3}; // Output Gate 1

			m_vLinks[3] = {1, 3}; // Output Gate 2
			m_vLinks[4] = {1, 2}; // Input Gate 2
			m_vLinks[5] = {1, 1}; // Input Gate 2
            
			m_vLinks[6] = {-1, -1};	// Null

			m_vLinks[7] = {2, 1}; // Input Gate 3
			m_vLinks[8] = {2, 2}; // Input Gate 3
			m_vLinks[9] = {2, 3}; // Output Gate 3

			m_vLinks[10] = {3, 3}; // Output Gate 4
			m_vLinks[11] = {3, 2}; // Input Gate 4
			m_vLinks[12] = {3, 1}; // Input Gate 4

			m_vLinks[13] = {-1, -1}; // Null
        }

        ~FourGates() { }

        void setLink(PinID pin, nts::IComponent& other, PinID otherPin) override
        {
			if (pin == 0 || pin > m_iMaxPins)
				return;
			if (m_vLinks[--pin].first == -1)
				return;
			int iGateIdx = m_vLinks[pin].first;
			int iGatePin = m_vLinks[pin].second;
			m_vGates[iGateIdx].setLink(iGatePin, other, otherPin);
        }

        nts::Tristate compute(PinID pin) override
        {
            if (pin < 1 || pin > m_iMaxPins)
		        throw InvalidPin(m_strName, pin);
            --pin;
			if (m_vLinks[pin].first == -1)
				return nts::Tristate::UNDEFINED;
			int iGateIdx = m_vLinks[pin].first;
			int iGatePin = m_vLinks[pin].second;
            return m_vGates[iGateIdx].compute(iGatePin);
        }

        void dump() const override
        {
            for (const auto& gate : m_vGates)
            {
                gate.dump();
            }
        }

    private:
        T m_vGates[4];
        std::pair<int, int> m_vLinks[14];
    };
} // namespace nts

#endif