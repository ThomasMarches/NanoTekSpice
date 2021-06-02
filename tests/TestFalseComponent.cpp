

#ifdef __linux__
#include <criterion/criterion.h>

#include "FalseComponent.hpp"
#include "Input.hpp"

Test(FalseComponent, compute)
{
    nts::FalseComponent component;

    cr_assert_eq(component.compute(), nts::FALSE);
}

#endif