
#ifndef NTS_INVALID_PIN_EXCEPTION_HPP_
#define NTS_INVALID_PIN_EXCEPTION_HPP_

#include "AException.hpp"

class InvalidPin : public AException
{
public:
    InvalidPin(const std::string& strName, std::size_t lPin) throw();
    virtual ~InvalidPin() throw();
};

#endif