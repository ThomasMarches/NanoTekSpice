#include <iostream>

#include "Parser.hpp"
#include "Shell.hpp"
#include "Exceptions/AException.hpp"

int main(int ac, char** av)
{
    nts::Shell shell;
    nts::Parser parser(shell.m_oCircuit);
    std::string strText;
    try {
        if (nts::ReadFile(av[1], strText))
        {
            parser.Process(strText);
            shell.run();
        }
    } catch (AException& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}