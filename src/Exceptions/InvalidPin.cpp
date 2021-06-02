
#include "Exceptions/InvalidPin.hpp"

InvalidPin::InvalidPin(const std::string& strName, std::size_t lPin) throw()
	: AException("Invalid pin '"+ std::to_string(lPin) + "' in component '" + strName + "'.") { }

InvalidPin::~InvalidPin() throw() { }