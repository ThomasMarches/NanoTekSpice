/*
** EPITECH PROJECT, 2020
** B-OOP-400-TLS-4-1-tekspice-samuel.besseau
** File description:
** Factory.cpp
*/

#include "Factory.hpp"
#include "4069.hpp"
#include "4008.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "FourGates.hpp"
#include "XorGate.hpp"
#include "NorGate.hpp"
#include "NAndGate.hpp"
#include "AndGate.hpp"
#include "OrGate.hpp"
#include "Clock.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "Exceptions/ComponentNotFound.hpp"

namespace nts
{
    Factory::Factory()
    {
        f_ptrmap["4001"] = &nts::Factory::_4001;
        f_ptrmap["4011"] = &nts::Factory::_4011;
        f_ptrmap["4030"] = &nts::Factory::_4030;
        f_ptrmap["4071"] = &nts::Factory::_4071;
        f_ptrmap["4081"] = &nts::Factory::_4081;
        f_ptrmap["4069"] = &nts::Factory::_4069;
        // f_ptrmap["4008"] = &nts::Factory::_4008;
        // f_ptrmap["4013"] = &nts::Factory::_4013;
        // f_ptrmap["4017"] = &nts::Factory::_4017;
        // f_ptrmap["4040"] = &nts::Factory::_4040;
        // f_ptrmap["4094"] = &nts::Factory::_4094;
        // f_ptrmap["4512"] = &nts::Factory::_4512;
        // f_ptrmap["4514"] = &nts::Factory::_4514;
        // f_ptrmap["4801"] = &nts::Factory::_4801;
        // f_ptrmap["2716"] = &nts::Factory::_2716;
        // f_ptrmap["logger"] = &nts::Factory::_logger;
        f_ptrmap["clock"] = &nts::Factory::_clock;
        f_ptrmap["input"] = &nts::Factory::_input;
        f_ptrmap["output"] = &nts::Factory::_output;
        f_ptrmap["true"] = &nts::Factory::_true;
        f_ptrmap["false"] = &nts::Factory::_false;
    }

    Factory::~Factory() {}

    std::unique_ptr<nts::IComponent> Factory::_4001()
    {
        return std::unique_ptr<nts::IComponent>(new FourGates<NorGate>());
    }

    std::unique_ptr<nts::IComponent> Factory::_4011()
    {
        return std::unique_ptr<nts::IComponent>(new FourGates<NAndGate>());
    }

    std::unique_ptr<nts::IComponent> Factory::_4030()
    {
        return std::unique_ptr<nts::IComponent>(new FourGates<XorGate>());
    }

    std::unique_ptr<nts::IComponent> Factory::_4071()
    {
        return std::unique_ptr<nts::IComponent>(new FourGates<OrGate>());
    }

    std::unique_ptr<nts::IComponent> Factory::_4081()
    {
        return std::unique_ptr<nts::IComponent>(new FourGates<AndGate>());
    }

    std::unique_ptr<nts::IComponent> Factory::_4069()
    {
        return std::unique_ptr<nts::IComponent>(new Component4069());
    }

    // std::unique_ptr<nts::IComponent> Factory::_4008()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4008());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4013()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4017()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4040()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4094()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4512()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4514()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_4801()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_2716()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    // std::unique_ptr<nts::IComponent> Factory::_logger()
    // {
    //     return std::unique_ptr<nts::IComponent>(new Component4069());
    // }

    std::unique_ptr<nts::IComponent> Factory::_input()
    {
        return std::unique_ptr<nts::IComponent>(new Input());
    }

    std::unique_ptr<nts::IComponent> Factory::_output()
    {
        return std::unique_ptr<nts::IComponent>(new Output());
    }

    std::unique_ptr<nts::IComponent> Factory::_clock()
    {
        return std::unique_ptr<nts::IComponent>(new Clock());
    }

    std::unique_ptr<nts::IComponent> Factory::_true()
    {
        return std::unique_ptr<nts::IComponent>(new TrueComponent());
    }

    std::unique_ptr<nts::IComponent> Factory::_false()
    {
        return std::unique_ptr<nts::IComponent>(new FalseComponent());
    }

    std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string str)
    {
        auto f_ptr = f_ptrmap.find(str);

        if (f_ptr == f_ptrmap.end())
        {
            throw AException("Unknown Component '" + str + "' in NanoTekSpice's Factory");
        }

        return (this->*f_ptr->second)();
    }
}