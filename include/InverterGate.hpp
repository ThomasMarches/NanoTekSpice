/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** InverterGate.hpp
*/

#include "AComponent.hpp"

#if !defined(_InverterGate_)
#define _InverterGate_

namespace nts
{
    class InverterGate : public AComponent
    {
    public:
        InverterGate();
        ~InverterGate();
        nts::Tristate precompute(nts::Tristate a);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif