
#ifndef NTS_UNKNOWN_VALUE_EXCEPTION_HPP_
#define NTS_UNKNOWN_VALUE_EXCEPTION_HPP_

#include "AException.hpp"

class UnknownValueException : public AException
{
public:
    UnknownValueException(const std::string& strValue) throw();
    virtual ~UnknownValueException() throw();
};

#endif