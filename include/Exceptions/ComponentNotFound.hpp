
#ifndef NTS_COMPONENT_NOT_FOUND_EXCEPTION_HPP_
#define NTS_COMPONENT_NOT_FOUND_EXCEPTION_HPP_

#include "AException.hpp"

class ComponentNotFound : public AException
{
public:
    ComponentNotFound(const std::string &) throw();
    virtual ~ComponentNotFound() throw();
};

#endif