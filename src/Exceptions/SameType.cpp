
#include "Exceptions/SameType.hpp"

SameType::SameType(const std::string& strType) throw()
	: AException("Cannot link to the same type of '" + strType + "'.") { }

SameType::~SameType() throw() { }