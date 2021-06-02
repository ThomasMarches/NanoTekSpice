

#include "AComponent.hpp"

#if !defined(_NOR_GATE_HPP_)
#define _NOR_GATE_HPP_

namespace nts
{
    class NorGate : public AComponent
    {
    public:
        NorGate();
        ~NorGate();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif