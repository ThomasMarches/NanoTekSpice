/*
** EPITECH PROJECT, 2020
** B-OOP-400-TLS-4-1-tekspice-samuel.besseau
** File description:
** TrueComponent.hpp
*/

#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public nts::AComponent
    {
    public:
        TrueComponent();
        ~TrueComponent();
        void dump() const override;
    };
}