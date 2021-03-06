#ifndef DEADSTORM_MATH_HPP
#define DEADSTORM_MATH_HPP

#include <cmath>

namespace Deadstorm
{
    namespace Tools
    {
        template<class T>
        inline bool IsEqual(T a, T b, T c)
        {
            T diff = a - b;
            if (diff < 0)
                diff = -diff;

            return diff < c;
        }


        template<class _T>
        _T GetDistance(_T fromX, _T fromY, _T toX, _T toY)
        {
            _T diffX = fromX - toX;
            _T diffY = fromY - toY;

            return std::sqrt((diffX * diffX) + (diffY * diffY));
        }
    }
}

#endif //DEADSTORM_MATH_HPP
