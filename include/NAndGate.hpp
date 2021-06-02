

#include "AComponent.hpp"

#if !defined(_NAND_GATE_HPP_)
#define _NAND_GATE_HPP_

namespace nts
{
    class NAndGate : public AComponent
    {
    public:
        NAndGate();
        ~NAndGate();
        nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
        nts::Tristate compute(PinID pin = 1) override;
        void dump() const override;
    private:
    };
}

#endif