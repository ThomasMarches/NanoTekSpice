
#include <csignal>
#include "Shell.hpp"
#include "Exceptions/UnknownValueException.hpp"

namespace nts
{
    bool Shell::m_bIsLooping = false;

    Shell::Shell()
    {
        m_oLex.m_bEnableError = true;
        m_oLex.Define("WS", "[ \t\r\b]+", true);
        m_oLex.Define("LineComment", "#[^\n\r]*", true);
        m_oLex.Define("NewLine", "\n");
        m_oLex.Define("Number", "[0-9]+");
        m_oLex.Define("Statement", "\\.[A-Za-z_]+[0-9]*");
        m_oLex.Define("Colon", ":");
        m_oLex.Define("Link", "[A-Za-z_]+[0-9]*:[0-9]+");
        m_oLex.Define("Identifier", "[A-Za-z_]+[0-9]*");
        m_oLex.Define("Eof", "\\0");
    }

    Shell::~Shell()
    {
    }
    
    void Shell::run()
    {
        for (std::string line;;) {
            std::cout << "> ";
            if (!std::getline(std::cin, line))
                break;
            m_oLex.Process(line);
            if (line.find("=") != line.npos) {
                std::string strVarName = m_oLex[0].GetText();
                std::string strValue = m_oLex[2].GetText();
                nts::CompPtr pComp = m_oCircuit.getComp(strVarName);

                if (strValue == "0") {
                    pComp->setValue(nts::FALSE);
                } else if (strValue == "1") {
                    pComp->setValue(nts::TRUE);
                } else if (strValue == "U") {
                    pComp->setValue(nts::UNDEFINED);
                } else {
                    throw UnknownValueException(strValue);
                }
            }
            if (line == "exit") {
                // closes the program.
                return;
            }
            if (line == "display") {
                // prints the current tick and the value of all inputs and outputs the standard output, each sorted by name in ASCII order.
                m_oCircuit.display();
            }
            if (line == "simulate") {
                // simulate a tick of the circuit.
                m_oCircuit.simulate();
            }
            if (line == "loop") {
                // continuously runs the simulation (simulate, display, simulate, ...) without displaying a prompt, until SIGINT is received.
                signal(SIGINT, Shell::reset);
                Shell::m_bIsLooping = true;
                while (Shell::m_bIsLooping) {
                    m_oCircuit.simulate();
                    m_oCircuit.display();
                }
            }
            if (line == "dump") {
                // calls the dump method of every component. The output format is free.
                m_oCircuit.dump();
            }
        }
    }

    void Shell::reset(int sig)
    {
        Shell::m_bIsLooping = false;
    }
} // namespace nts
