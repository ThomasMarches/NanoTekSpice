/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Handler.cpp
*/

#include "IComponent.hpp"

namespace nts
{
    std::string TristateToString(Tristate eState)
    {
        if (eState == UNDEFINED)
            return "U";
        if (eState == TRUE)
            return "1";
        return "0";
    }
}
