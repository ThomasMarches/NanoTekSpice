/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** 4069.hpp
*/

#include "AComponent.hpp"
#include "InverterGate.hpp"

#if !defined(_COMPONENT_4069_)
#define _COMPONENT_4069_

namespace nts
{
    class Component4069 : public nts::AComponent
    {
    public:
        Component4069();
        ~Component4069();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        void setLink(PinID pin, nts::IComponent& other, PinID otherPin) override;
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
        nts::InverterGate m_vGates[6];
        std::pair<int, int> m_vLinks[14];
    };
}

#endif