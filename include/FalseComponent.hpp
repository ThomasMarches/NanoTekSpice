/*
** EPITECH PROJECT, 2020
** B-OOP-400-TLS-4-1-tekspice-samuel.besseau
** File description:
** FalseComponent.hpp
*/

#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public nts::AComponent
    {
    public:
        FalseComponent();
        ~FalseComponent();
        void dump() const override;
    };
}