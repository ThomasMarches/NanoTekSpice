

#include <unordered_map>
#include <utility>
#include "AComponent.hpp"
#include "Factory.hpp"
#include "Input.hpp"
#include "Output.hpp"

#if !defined(_CIRCUIT_HPP_)
#define _CIRCUIT_HPP_

namespace nts
{
    using CompPtr = IComponent*;
    using CompUniquePtr = std::unique_ptr<IComponent>;
    using CompList = std::unordered_map<std::string, CompUniquePtr>;
    class Circuit
    {
    public:
        Circuit();
        ~Circuit();
        void addComp(const std::string& strType, const std::string strName);
        void dump() const;
        void display() const;
        void simulate();
        CompPtr getComp(const std::string& strComp1);
        void setLink(const std::string& strComp1, PinID pin1, const std::string& strComp2, PinID pin2);

    private:
        CompList m_vComponents;
        std::vector<Input*> m_vInputs;
        std::vector<Output*> m_vOutputs;
        Factory m_oFactory;
        std::size_t m_lTick;
    };
}

#endif