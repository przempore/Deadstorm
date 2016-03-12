#include "gem/Rectangle.hpp"

#include "gmock/gmock.h"

using namespace testing;

namespace Gem
{
    TEST(RectangleTest, Constructor)
    {
        Rectangle rectangle1;

        ASSERT_THAT(rectangle1.m_x, Eq(0));
        ASSERT_THAT(rectangle1.m_y, Eq(0));
        ASSERT_THAT(rectangle1.m_width, Eq(0));
        ASSERT_THAT(rectangle1.m_height, Eq(0));

        const int x2 = 1;
        const int y2 = 2;
        const int width2 = 3;
        const int height2 = 4;

        Rectangle rectangle2(x2, y2, width2, height2);

        ASSERT_THAT(rectangle2.m_x, Eq(x2));
        ASSERT_THAT(rectangle2.m_y, Eq(y2));
        ASSERT_THAT(rectangle2.m_width, Eq(width2));
        ASSERT_THAT(rectangle2.m_height, Eq(height2));
    }

    TEST(RectangleTest, Empty)
    {
        ASSERT_THAT(Rectangle::s_empty.m_x, Eq(0));
        ASSERT_THAT(Rectangle::s_empty.m_y, Eq(0));
        ASSERT_THAT(Rectangle::s_empty.m_width, Eq(0));
        ASSERT_THAT(Rectangle::s_empty.m_height, Eq(0));
    }
}
