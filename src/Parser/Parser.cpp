/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** parser.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include "Parser.hpp"
#include "Exceptions/ParserException.hpp"

static const char *KEYWORDS[] = {
    "input",
    "output",
    "clock",
    "true",
    "false",
    "4001",
    "4011",
    "4030",
    "4071",
    "4081",
    "4069",
    "4008",
    "4013",
    "4017",
    "4040",
    "4094",
    "4512",
    "4514",
    "4801",
    "2716",
    "logger",
    nullptr
};

namespace nts
{
    bool ReadFile(const std::string& strFile, std::string& strOutReadContent)
    {
        std::ifstream oFile(strFile); //open the input file
        if (!oFile.is_open())
            return false;

        std::stringstream strStream;
        strStream << oFile.rdbuf(); //read the file
        strOutReadContent = strStream.str();
        return true;
    }

    Parser::Parser(Circuit& oCircuit) : m_oCircuit(oCircuit)
    {
        Define("WS", "[ \t\r\b]+", true);
        Define("LineComment", "#[^\n\r]*", true);
        Define("NewLine", "\n");
        Define("Number", "[0-9]+");
        Define("Statement", "\\.[A-Za-z_]+[0-9]*");
        Define("Colon", ":");
        Define("Link", "[A-Za-z_]+[0-9]*:[0-9]+");
        Define("Identifier", "[A-Za-z_]+[0-9]*");
        Define("Eof", "\\0");
    }

    Parser::~Parser()
    {
    }

    void Parser::RemoveUnnecessryLine()
    {
        int iIndex = 0;
        Lexer& oLex = GetLexer();
        oLex.oTokenList.erase(std::remove_if(oLex.oTokenList.begin(), oLex.oTokenList.end(), [&iIndex, &oLex](const Token& oToken)
        {
            std::vector<Token>::iterator oNextToken = oLex.oTokenList.begin() + iIndex + 1;
            iIndex++;
            return oToken.GetText() == "\n" && oNextToken->GetText() == "\n";
        }), oLex.oTokenList.end());
    }
    
    void Parser::GetLinkInfo(std::string& strName, std::size_t& strPin)
    {
        Token oToken;
        if (!IsTokenThenAssign("Link", oToken))
            throw ParserException(CurrentToken(), "Expected this correct format '<comp-name>:<value>'.");
        std::string s = oToken.GetText();
        std::size_t lIndex = s.find(":");
        strName = s.substr(0, lIndex);
        strPin = std::stoul(s.substr(lIndex + 1));
    }

    void Parser::ExpectedStatement(const std::string& strName)
    {
        if (!IsToken(strName))
            throw ParserException(CurrentToken(), "Missing '" + strName + "' statement.");
        if (!IsToken(":"))
            throw ParserException(CurrentToken(), "Expected ':'.");
        if (!IsTokenType("NewLine"))
            throw ParserException(CurrentToken(), "Expected '<new-line>'.");
    }

    bool Parser::Process(const std::string strText)
    {
        Token token;

        if (!Init(strText))
            return false;
        RemoveUnnecessryLine();
        IsTokenType("NewLine");
        ExpectedStatement(".chipsets");
        while (!IsTokenType("Statement", false) && !IsEnd()) {
            bool bFound = false;
            // Type de la variable
            for (int i = 0; KEYWORDS[i]; ++i) {
                if (IsToken(KEYWORDS[i])) {
                    if (!IsTokenThenAssign("Identifier", token))
                        throw ParserException(CurrentToken(), "Expected variable name.");
                    m_oCircuit.addComp(KEYWORDS[i], token.GetText());
                    bFound = true;
                    break;
                }
            }
            // Error : unknown component
            if (!bFound)
                throw ParserException(CurrentToken(), "Component '" + CurrentToken().GetText() + "' not found.");

            // Error
            if (!IsTokenType("NewLine"))
                throw ParserException(CurrentToken(), "Expected '<new-line>'.");
        }

        ExpectedStatement(".links");
        while (!IsEnd()) {
            std::string strCompName1;
            std::size_t strCompPin1;
            std::string strCompName2;
            std::size_t strCompPin2;
            GetLinkInfo(strCompName1, strCompPin1);
            GetLinkInfo(strCompName2, strCompPin2);
            m_oCircuit.setLink(strCompName1, strCompPin1, strCompName2, strCompPin2);

            // Error
            if (!IsTokenType("NewLine") && !IsEnd())
                throw ParserException(CurrentToken(), "Expected '<new-line>'.");
        }
        return (true);
    }
}