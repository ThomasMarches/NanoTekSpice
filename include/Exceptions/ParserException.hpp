
#ifndef NTS_PARSER_EXCEPTION_HPP_
#define NTS_PARSER_EXCEPTION_HPP_

#include "AException.hpp"
#include "Lexer.h"

class ParserException : public AException
{
public:
    ParserException(const Token& oToken, const std::string &) throw();
    virtual ~ParserException() throw();
};

#endif