/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    TrueComponent::TrueComponent() : AComponent(1)
    {
        m_vValues[0] = nts::TRUE;
        m_bNeedToCompute = false;
    }

    TrueComponent::~TrueComponent() {}

    void TrueComponent::dump() const
    {
        
    }
}