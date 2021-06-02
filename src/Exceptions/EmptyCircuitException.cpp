
#include "Exceptions/EmptyCircuitException.hpp"

EmptyCircuitException::EmptyCircuitException() throw()
	: AException("No chipsets in the circuit.") { }
EmptyCircuitException::~EmptyCircuitException() throw() { }