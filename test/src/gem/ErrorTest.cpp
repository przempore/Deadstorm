#include "gem/Error.hpp"

#include "gmock/gmock.h"

using namespace testing;

namespace Gem
{
    TEST(ErrorTest, Constructor)
    {
        const char* what = "error";

        Error error(what);

        ASSERT_THAT(error.What(), Eq(what));
    }
}
