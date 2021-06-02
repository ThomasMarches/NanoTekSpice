

#include "AComponent.hpp"

#if !defined(_AND_GATE_HPP_)
#define _AND_GATE_HPP_

namespace nts
{
    class AndGate : public nts::AComponent
    {
    public:
        AndGate();
        ~AndGate();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif