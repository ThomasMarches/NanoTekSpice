
#ifndef NTS_SAME_TYPE_EXCEPTION_HPP_
#define NTS_SAME_TYPE_EXCEPTION_HPP_

#include "AException.hpp"

class SameType : public AException
{
public:
    SameType(const std::string& strType) throw();
    virtual ~SameType() throw();
};

#endif