/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** 4008.cpp
*/

#include "4008.hpp"

namespace nts
{
    Component4008::Component4008() : AComponent(0)
    {
        m_vLinks[0] = {0, 1}; // Input Gate 1
        m_vLinks[1] = {0, 2}; // Output Gate 1

        m_vLinks[2] = {1, 1}; // Input Gate 2
        m_vLinks[3] = {1, 2}; // Output Gate 2

        m_vLinks[4] = {2, 1}; // Input Gate 3
        m_vLinks[5] = {2, 2}; // Output Gate 3

        m_vLinks[6] = {-1, -1}; // Null

        m_vLinks[7] = {3, 2}; // Output Gate 4
        m_vLinks[8] = {3, 1}; // Input Gate 4

        m_vLinks[9] = {4, 2}; // Output Gate 5
        m_vLinks[10] = {4, 1}; // Input Gate 5
    
        m_vLinks[11] = {5, 2}; // Output Gate 6
        m_vLinks[12] = {5, 1}; // Input Gate 6

        m_vLinks[13] = {-1, -1}; // Null
    }

    Component4008::~Component4008() {}

    void Component4008::setLink(PinID pin, nts::IComponent& other, PinID otherPin)
    {
        if (pin == 0 || pin > m_iMaxPins)
            return;
        if (m_vLinks[--pin].first == -1)
            return;
        int iGateIdx = m_vLinks[pin].first;
        int iGatePin = m_vLinks[pin].second;
        m_vGates[iGateIdx].setLink(iGatePin, other, otherPin);
    }

    nts::Tristate Component4008::compute(PinID pin) 
    {
        if (pin == 0 || pin > m_iMaxPins)
            return nts::Tristate::UNDEFINED;
        if (m_vLinks[--pin].first == -1)
            return nts::Tristate::UNDEFINED;
        int iGateIdx = m_vLinks[pin].first;
        int iGatePin = m_vLinks[pin].second;            
        return m_vGates[iGateIdx].compute(iGatePin);
    }

    void Component4008::dump() const
    {
        for (const auto& gate : m_vGates)
        {
            gate.dump();
        }
    }
}