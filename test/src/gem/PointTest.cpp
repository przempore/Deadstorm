#include "gem/Point.hpp"

#include "gmock/gmock.h"

using namespace testing;

namespace Gem
{
    TEST(PointTest, Constructor)
    {
        Point point1;

        ASSERT_THAT(point1.m_x, Eq(0));
        ASSERT_THAT(point1.m_y, Eq(0));

        const int x2 = 1;
        const int y2 = 2;

        Point point2(x2, y2);

        ASSERT_THAT(point2.m_x, Eq(x2));
        ASSERT_THAT(point2.m_y, Eq(y2));
    }

    TEST(PointTest, Zero)
    {
        ASSERT_THAT(Point::s_zero.m_x, Eq(0));
        ASSERT_THAT(Point::s_zero.m_y, Eq(0));
    }
}
