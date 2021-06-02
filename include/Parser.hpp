

#include "ParserHelper.hpp"
#include "Circuit.hpp"

#if !defined(_PARSER_HPP_)
#define _PARSER_HPP_

#include <string>

namespace nts
{
    class Parser : public ParserHelper
    {
    public:
        Parser(Circuit& circuit);
        ~Parser();
        bool Process(const std::string strText);
        void RemoveUnnecessryLine();
        void GetLinkInfo(std::string& strName, std::size_t& strPin);
        void ExpectedStatement(const std::string& strName);
    private:
        Circuit& m_oCircuit;
    };

    bool ReadFile(const std::string& strFile, std::string& strOutReadContent);
}

#endif