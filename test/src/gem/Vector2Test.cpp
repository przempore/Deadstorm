#include "gem/Vector2.hpp"

#include "gmock/gmock.h"

using namespace testing;

namespace Gem
{
    TEST(Vector2Test, Constructor)
    {
        Vector2 vector1;

        ASSERT_THAT(vector1.m_x, Eq(0.f));
        ASSERT_THAT(vector1.m_y, Eq(0.f));

        const float x2 = 1.f;
        const float y2 = 2.f;

        Vector2 vecotr2(x2, y2);

        ASSERT_THAT(vecotr2.m_x, Eq(x2));
        ASSERT_THAT(vecotr2.m_y, Eq(y2));
    }

    TEST(Vector2Test, Zero)
    {
        ASSERT_THAT(Vector2::s_zero.m_x, Eq(0));
        ASSERT_THAT(Vector2::s_zero.m_y, Eq(0));
    }
}
