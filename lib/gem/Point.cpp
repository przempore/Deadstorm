#include "gem/Point.hpp"

namespace Gem
{
    const Point Point::s_zero{0, 0};

    bool Point::operator==(Point &p)
    {
        return m_x == p.m_x
               && m_y == p.m_y;
    }

    bool Point::operator!=(Point &p)
    {
        return !(*this == p);
    }
}
