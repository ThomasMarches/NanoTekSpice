
#ifndef NTS_COMPONENT_ALREADY_EXIST_EXCEPTION_HPP_
#define NTS_COMPONENT_ALREADY_EXIST_EXCEPTION_HPP_

#include "AException.hpp"

class ComponentAlreadyExist : public AException
{
public:
    ComponentAlreadyExist(const std::string &) throw();
    virtual ~ComponentAlreadyExist() throw();
};

#endif