

// #include "AComponent.hpp"
// #include "NorGate.hpp"

// #if !defined(_XOR_GATE_HPP_)
// #define _XOR_GATE_HPP_

// namespace nts
// {
//     class FlipFlop : public AComponent
//     {
//     public:
//         FlipFlop();
//         ~FlipFlop();
//         nts::Tristate precompute(nts::Tristate a, nts::Tristate b);
//         nts::Tristate compute(PinID pin = 1) override;
//         void dump() const override;
//     private:
//         NorGate m_vNorGates[2];
//     };
// }

// #endif