
#ifndef NTS_EMPTY_CIRCUIT_EXCEPTION_HPP_
#define NTS_EMPTY_CIRCUIT_EXCEPTION_HPP_

#include "AException.hpp"
#include "Lexer.h"

class EmptyCircuitException : public AException
{
public:
    EmptyCircuitException() throw();
    virtual ~EmptyCircuitException() throw();
};

#endif