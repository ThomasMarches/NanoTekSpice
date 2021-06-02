
#include "Input.hpp"

#if !defined(_CLOCK_HPP_)
#define _CLOCK_HPP_

namespace nts
{
    class Clock : public Input
    {
    public:
        Clock();
        ~Clock();
        void dump() const override;
        nts::Tristate compute(PinID pin = 1);
    private:
    };
    
} // namespace nts


#endif