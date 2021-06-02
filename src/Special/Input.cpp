

#include "Input.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    Input::Input() : AComponent(1)
    {
        m_bNeedToCompute = false;
    }
    
    Input::~Input()
    {
    }

    void Input::dump() const
    {
        std::cout << getName() << ": " << TristateToString(m_vValues[0]) << std::endl;
    }
}