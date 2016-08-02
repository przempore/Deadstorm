#ifndef GEM_POINT_HPP
#define GEM_POINT_HPP

namespace Gem
{
    class Point
    {
    public:
        inline Point();
        inline Point(int x, int y);

    public:
        static const Point s_zero;

    public:
        bool operator==(Point &p);
        bool operator!=(Point &p);

    public:
        int m_x;
        int m_y;
    };
}

#include "gem/Point.inl"

#endif
