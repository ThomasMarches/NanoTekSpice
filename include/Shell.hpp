

#include <vector>
#include "Lexer.h"
#include "Circuit.hpp"

#if !defined(_SHELL_HPP_)
#define _SHELL_HPP_

namespace nts
{
    class Shell
    {
    public:
        Shell();
        ~Shell();
        void run();
        static void reset(int sig);
    
    public:
        Circuit m_oCircuit;
    private:
        Lexer m_oLex;
        static bool m_bIsLooping;
    };
}

#endif