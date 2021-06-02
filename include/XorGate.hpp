

#include "AComponent.hpp"

#if !defined(_XOR_GATE_HPP_)
#define _XOR_GATE_HPP_

namespace nts
{
    class XorGate : public AComponent
    {
    public:
        XorGate();
        ~XorGate();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif