

#include "AComponent.hpp"

#if !defined(_OR_GATE_HPP_)
#define _OR_GATE_HPP_

namespace nts
{
    class OrGate : public AComponent
    {
    public:
        OrGate();
        ~OrGate();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif