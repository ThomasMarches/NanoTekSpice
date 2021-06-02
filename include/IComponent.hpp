//
// EPITECH PROJECT, 2020
// IComponent
// File description:
// Interface file
//

#include <iostream>
#include <memory>

#if !defined(_ICOMPONENT_HPP_)
#define _ICOMPONENT_HPP_

namespace nts
{
    class IComponent;
}

namespace nts
{
    using PinID = std::size_t;
    using RefComp = std::unique_ptr<nts::IComponent>;
	enum Tristate
    {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	std::string TristateToString(Tristate eState);

	class Links
    {
	public:
		Links()
        {
            m_pComponent = nullptr;
            m_iPinId = 0;
        };
		IComponent* m_pComponent;
		PinID m_iPinId;
	};

	class IComponent
    {
	public:
		virtual ~IComponent() = default;

		virtual void setLink(PinID pin, nts::IComponent& other, PinID otherPin) = 0;
    	virtual const Links& getLink(PinID pin) = 0;
		virtual nts::Tristate compute(PinID pin = 1) = 0;
		virtual void dump() const = 0;
		virtual std::string getName() const = 0;
        virtual void setName(const std::string& strName) = 0;
    	virtual void setValue(nts::Tristate eValue) = 0;
	};
}

#endif /* !ICOMPONENT_HPP_ */