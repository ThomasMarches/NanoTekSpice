
#include "Exceptions/ParserException.hpp"

ParserException::ParserException(const Token& oToken, const std::string& strMsg) throw()
	: AException("[line " + std::to_string(oToken.m_iLinesTraversed) + "] " + strMsg) { }
ParserException::~ParserException() throw() { }