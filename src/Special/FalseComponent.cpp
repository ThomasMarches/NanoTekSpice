/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** FalseComponent.cpp
*/

#include "FalseComponent.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    FalseComponent::FalseComponent() : AComponent(1)
    {
        m_vValues[0] = nts::FALSE;
        m_bNeedToCompute = false;
    }

    FalseComponent::~FalseComponent() {}

    void FalseComponent::dump() const
    {

    }
}