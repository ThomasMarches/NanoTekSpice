

#include <vector>
#include "IComponent.hpp"

#if !defined(_ACOMPONENT_HPP_)
#define _ACOMPONENT_HPP_

namespace nts
{
    class AComponent : public nts::IComponent
    {
    public:
        AComponent(int iMaxPins);
        ~AComponent();
        virtual void setLink(PinID pin, nts::IComponent& other, PinID otherPin);
        virtual const Links& getLink(PinID pin);
        virtual nts::Tristate compute(PinID pin = 1);
        void dump() const = 0;
        virtual std::string getName() const;
        virtual void setName(const std::string& strName);
    	virtual void setValue(nts::Tristate eValue);
    protected:
        std::string m_strName;
        int m_iMaxPins;
        std::vector<nts::Links> m_vPins;
        std::vector<nts::Tristate> m_vValues;
        bool m_bNeedToCompute;
    };
}

#endif