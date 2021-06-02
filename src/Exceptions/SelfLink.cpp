
#include "Exceptions/SelfLink.hpp"

SelfLink::SelfLink(const std::string& strName, std::size_t lPin) throw()
	: AException("Cannot link on itself on the pin '"+ std::to_string(lPin) + "' of the component '" + strName + "'.") { }

SelfLink::~SelfLink() throw() { }