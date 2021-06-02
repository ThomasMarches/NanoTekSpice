
#include "AComponent.hpp"

#if !defined(_INPUT_HPP_)
#define _INPUT_HPP_

namespace nts
{
    class Input : public AComponent
    {
    public:
        Input();
        ~Input();
        void dump() const override;
    private:
    };
    
} // namespace nts

#endif