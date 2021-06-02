

#ifdef __linux__
#include <criterion/criterion.h>

#include "InverterGate.hpp"
#include "Input.hpp"

Test(InverterGate, precompute)
{
    nts::InverterGate gate;
    cr_assert_eq(gate.precompute(nts::TRUE), nts::FALSE);
    cr_assert_eq(gate.precompute(nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.precompute(nts::UNDEFINED), nts::UNDEFINED);
}

Test(InverterGate, compute)
{
    nts::InverterGate gate;
    nts::Input input0;

    // Links
    gate.setLink(1, input0, 1);

    input0.setValue(nts::TRUE);
    cr_assert_eq(gate.compute(), nts::FALSE);

    input0.setValue(nts::FALSE);
    cr_assert_eq(gate.compute(), nts::TRUE);

    input0.setValue(nts::UNDEFINED);
    cr_assert_eq(gate.compute(), nts::UNDEFINED);
}
#endif