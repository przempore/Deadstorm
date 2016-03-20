#ifndef GEM_EASING_HPP
#define GEM_EASING_HPP

namespace Gem
{
    template <class T_>
    inline T_ LinearEase(const T_& start, const T_& offset, float timeElapsed, float duration)
    {
        return T_(start + (timeElapsed/duration) * offset);
    }

    template <class T_>
    inline T_ CubicEaseIn(const T_& start, const T_& offset, float timeElapsed, float duration)
    {
        return T_(start + offset
        * (timeElapsed /= duration)
        * timeElapsed * timeElapsed);
    }

    template <class T_>
    inline T_ CubicEaseOut(const T_& start, const T_& offset, float timeElapsed, float duration)
    {
        return T_(start + offset * ((timeElapsed = (timeElapsed / duration) - 1.f) * timeElapsed * timeElapsed + 1.f));
    }

    template <class T_>
    inline T_ CubicEaseInOut(const T_& start, const T_& offset, float timeElapsed, float duration)
    {
        if ((timeElapsed /= (duration / 2.f)) < 1.f)
        {
            return T_(start + offset / 2.f
            * timeElapsed
            * timeElapsed
            * timeElapsed);
        }
        else
        {
            return T_(start + offset / 2.f
            * ((timeElapsed -= 2.f)
            * timeElapsed
            * timeElapsed + 2.f));
        }
    }
}

#endif //GEM_EASING_HPP
