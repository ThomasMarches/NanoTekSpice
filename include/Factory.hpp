/*
** EPITECH PROJECT, 2020
** B-OOP-400-TLS-4-1-tekspice-samuel.besseau
** File description:
** Factory.hpp
*/

#include "AComponent.hpp"
#include <unordered_map>

#if !defined(_FACTORY_HPP_)
#define _FACTORY_HPP_

namespace nts
{
    class Factory
    {
    public:
        Factory();
        ~Factory();
        std::unique_ptr<nts::IComponent> createComponent(const std::string str);
        std::unique_ptr<nts::IComponent> _4001();
        std::unique_ptr<nts::IComponent> _4011();
        std::unique_ptr<nts::IComponent> _4030();
        std::unique_ptr<nts::IComponent> _4071();
        std::unique_ptr<nts::IComponent> _4081();
        std::unique_ptr<nts::IComponent> _4069();
        // std::unique_ptr<nts::IComponent> _4008();
        // std::unique_ptr<nts::IComponent> _4013();
        // std::unique_ptr<nts::IComponent> _4017();
        // std::unique_ptr<nts::IComponent> _4040();
        // std::unique_ptr<nts::IComponent> _4094();
        // std::unique_ptr<nts::IComponent> _4512();
        // std::unique_ptr<nts::IComponent> _4514();
        // std::unique_ptr<nts::IComponent> _4801();
        // std::unique_ptr<nts::IComponent> _2716();
        // std::unique_ptr<nts::IComponent> _logger();
        std::unique_ptr<nts::IComponent> _input();
        std::unique_ptr<nts::IComponent> _output();
        std::unique_ptr<nts::IComponent> _clock();
        std::unique_ptr<nts::IComponent> _true();
        std::unique_ptr<nts::IComponent> _false();
    private:
        typedef std::unique_ptr<nts::IComponent> (nts::Factory::*f_ptr)();
        std::unordered_map<std::string, nts::Factory::f_ptr> f_ptrmap;
    };
    
} // namespace nts

#endif