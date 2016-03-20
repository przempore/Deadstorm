#ifndef GEM_INTERPOLATOR_HPP
#define GEM_INTERPOLATOR_HPP

#include "gem/Assert.hpp"
#include "gem/Easing.hpp"

namespace Gem
{
    template <class T_> class Interpolator
    {
    public:
        typedef T_ ValueType;

    public:
        inline Interpolator(const T_& value1,
        const T_& value2,
        float duration,
        typename Easing<T_>::Function easingFuncion) : m_value1(value1),
                                                       m_value2(value2),
                                                       m_duration(duration),
                                                       m_easingFuncion(easingFuncion)
        {
            GEM_ASSERT(easingFuncion);
        }

    public:
        inline const T_& Value1() const
        {
            return  m_value1;
        }

        inline const T_& Value2() const
        {
            return  m_value2;
        }

        inline float Duration() const
        {
            return m_duration;
        }

        typename Easing<T_>::Function EasingFunction() const
        {
            return m_easingFuncion;
        }

    public:
        inline bool Interpolate(T_& value, float timeElapsed)
        {
            if (timeElapsed <= 0.f)
            {
                value = m_value1;
                return false;
            }
            else if (timeElapsed >= m_duration)
            {
                value = m_value2;

                return false;
            }

            GEM_ASSERT((timeElapsed > 0.f) || (timeElapsed < m_duration));

            value = m_easingFuncion(m_value1, m_value2, timeElapsed, m_duration);

            return true;
        }

    private:
        T_ m_value1;
        T_ m_value2;
        float m_duration;
        typename Easing<T_>::Function m_easingFuncion;
    };
}

#endif //GEM_INTERPOLATOR_HPP
