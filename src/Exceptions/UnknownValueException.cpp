
#include "Exceptions/UnknownValueException.hpp"

UnknownValueException::UnknownValueException(const std::string& strValue) throw()
	: AException("Unknown value: '" + strValue + "'. Possibles values 'U', '0' and '1'") { }
UnknownValueException::~UnknownValueException() throw() { }