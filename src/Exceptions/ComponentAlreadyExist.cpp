
#include "Exceptions/ComponentAlreadyExist.hpp"

ComponentAlreadyExist::ComponentAlreadyExist(const std::string& strMsg) throw()
	: AException("Component '"+ strMsg + "' already exist.") { }

ComponentAlreadyExist::~ComponentAlreadyExist() throw() { }