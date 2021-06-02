

#include "Output.hpp"
#include "Exceptions/InvalidPin.hpp"

namespace nts
{
    Output::Output() : AComponent(1)
    {
    }
    
    Output::~Output()
    {
    }
    
    void Output::dump() const
    {
        std::cout << getName() << ": " << TristateToString(m_vValues[0]) << std::endl;
    }
}