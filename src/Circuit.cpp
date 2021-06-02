
#include <algorithm>
#include "Circuit.hpp"
#include "Exceptions/ComponentNotFound.hpp"
#include "Exceptions/ComponentAlreadyExist.hpp"
#include "Exceptions/EmptyCircuitException.hpp"
#include "Exceptions/SameType.hpp"

namespace nts
{
    Circuit::Circuit()
    {
        m_lTick = 0;
    }

    Circuit::~Circuit() { }

    CompPtr Circuit::getComp(const std::string& strName)
    {
        CompList::iterator it = m_vComponents.find(strName);
        if (it == m_vComponents.end())
            throw ComponentNotFound(strName);
        return it->second.get();
    }

    void Circuit::setLink(const std::string& strComp1, PinID pin1, const std::string& strComp2, PinID pin2)
    {
        CompPtr pComp1 = getComp(strComp1);
        CompPtr pComp2 = getComp(strComp2);
        std::vector<Input*>::iterator input1 = std::find(m_vInputs.begin(), m_vInputs.end(), pComp1);
        std::vector<Input*>::iterator input2 = std::find(m_vInputs.begin(), m_vInputs.end(), pComp2);
        std::vector<Output*>::iterator output1 = std::find(m_vOutputs.begin(), m_vOutputs.end(), pComp1);
        std::vector<Output*>::iterator output2 = std::find(m_vOutputs.begin(), m_vOutputs.end(), pComp2);
        if (input1 != m_vInputs.end() && input2 != m_vInputs.end())
            throw SameType("input");
        else if (output1 != m_vOutputs.end() && output2 != m_vOutputs.end())
            throw SameType("output");
        pComp1->setLink(pin1, *pComp2, pin2);
        pComp2->setLink(pin2, *pComp1, pin1);
    }

    void Circuit::addComp(const std::string& strType, const std::string strName)
    {
        if (m_vComponents.find(strName) != m_vComponents.end())
            throw ComponentAlreadyExist(strName);
        CompUniquePtr pComp = m_oFactory.createComponent(strType);
        pComp->setName(strName);

        if (strType == "output") {
            m_vOutputs.push_back(static_cast<Output*>(pComp.get()));
            std::sort(m_vOutputs.begin(), m_vOutputs.end(), [](Output* left, Output* right) {
                return left->getName() < right->getName();
            });
        }
        if (strType == "input") {
            m_vInputs.push_back(static_cast<Input*>(pComp.get()));
            std::sort(m_vInputs.begin(), m_vInputs.end(), [](Input* left, Input* right) {
                return left->getName() < right->getName();
            });
        }
        m_vComponents.emplace(strName, std::move(pComp));
    }

    void Circuit::simulate()
    {
        if (m_vComponents.empty())
            throw EmptyCircuitException();
        ++m_lTick;
        for (auto& it : m_vOutputs)
            it->compute();
    }

    void Circuit::display() const
    {
        std::cout << "tick: " << m_lTick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto out : m_vInputs) {
            std::cout << "  ";
            out->dump();
        }

        std::cout << "output(s):" << std::endl;
        for (auto out : m_vOutputs) {
            std::cout << "  ";
            out->dump();
        }
    }

    void Circuit::dump() const
    {
        std::cout << "components(s):" << std::endl;
        for (const auto& comp : m_vComponents)
        {
            std::cout << "  ";
            comp.second->dump();
        }
    }
}