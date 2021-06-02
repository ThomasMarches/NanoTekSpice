

#ifdef __linux__
#include <criterion/criterion.h>

#include "TrueComponent.hpp"
#include "Input.hpp"

Test(TrueComponent, compute)
{
    nts::TrueComponent component;

    cr_assert_eq(component.compute(), nts::TRUE);
}

#endif