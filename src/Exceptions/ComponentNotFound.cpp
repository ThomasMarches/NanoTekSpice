
#include "Exceptions/ComponentNotFound.hpp"

ComponentNotFound::ComponentNotFound(const std::string& strMsg) throw()
	: AException("Component '"+ strMsg + "' not found.") { }

ComponentNotFound::~ComponentNotFound() throw() { }