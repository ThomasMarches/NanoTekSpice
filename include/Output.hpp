
#include "AComponent.hpp"

#if !defined(_OUTPUT_HPP_)
#define _OUTPUT_HPP_

namespace nts
{
    class Output : public AComponent
    {
    public:
        Output();
        ~Output();
        void dump() const override;
    private:
    };
    
} // namespace nts


#endif