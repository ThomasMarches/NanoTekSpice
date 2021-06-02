
#ifdef __linux__
#include <criterion/criterion.h>

#include "OrGate.hpp"
#include "Input.hpp"

Test(OrGate, precompute)
{
    nts::OrGate gate;
    cr_assert_eq(gate.precompute(nts::TRUE, nts::TRUE), nts::TRUE);
    cr_assert_eq(gate.precompute(nts::FALSE, nts::TRUE), nts::TRUE);
    cr_assert_eq(gate.precompute(nts::TRUE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.precompute(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.precompute(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(gate.precompute(nts::FALSE, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.precompute(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.precompute(nts::TRUE, nts::UNDEFINED), nts::TRUE);
    cr_assert_eq(gate.precompute(nts::UNDEFINED, nts::TRUE), nts::TRUE);
}

Test(OrGate, compute)
{
    nts::OrGate gate;
    nts::Input input0;
    nts::Input input1;
    std::size_t lPinOut = 3;

    // Links
    gate.setLink(1, input0, 1);
    gate.setLink(2, input1, 1);

    input0.setValue(nts::TRUE);
    input1.setValue(nts::TRUE);
    cr_assert_eq(gate.compute(lPinOut), nts::TRUE);

    input0.setValue(nts::FALSE);
    input1.setValue(nts::TRUE);
    cr_assert_eq(gate.compute(lPinOut), nts::TRUE);

    input0.setValue(nts::TRUE);
    input1.setValue(nts::FALSE);
    cr_assert_eq(gate.compute(lPinOut), nts::TRUE);

    input0.setValue(nts::FALSE);
    input1.setValue(nts::FALSE);
    cr_assert_eq(gate.compute(lPinOut), nts::FALSE);

    input0.setValue(nts::UNDEFINED);
    input1.setValue(nts::FALSE);
    cr_assert_eq(gate.compute(lPinOut), nts::UNDEFINED);

    input0.setValue(nts::FALSE);
    input1.setValue(nts::UNDEFINED);
    cr_assert_eq(gate.compute(lPinOut), nts::UNDEFINED);

    input0.setValue(nts::UNDEFINED);
    input1.setValue(nts::TRUE);
    cr_assert_eq(gate.compute(lPinOut), nts::TRUE);

    input0.setValue(nts::TRUE);
    input1.setValue(nts::UNDEFINED);
    cr_assert_eq(gate.compute(lPinOut), nts::TRUE);

    input0.setValue(nts::UNDEFINED);
    input1.setValue(nts::UNDEFINED);
    cr_assert_eq(gate.compute(lPinOut), nts::UNDEFINED);
}
#endif