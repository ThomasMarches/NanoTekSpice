
#ifndef NTS_SELF_LINK_EXCEPTION_HPP_
#define NTS_SELF_LINK_EXCEPTION_HPP_

#include "AException.hpp"

class SelfLink : public AException
{
public:
    SelfLink(const std::string& strName, std::size_t lPin) throw();
    virtual ~SelfLink() throw();
};

#endif