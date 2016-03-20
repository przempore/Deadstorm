#ifndef GEM_TWEEN_HPP
#define GEM_TWEEN_HPP

#include "gem/FiniteAction.hpp"

namespace Gem
{
    template <class T_>
    class Tween : public FiniteAction
    {
    public:
        Tween(T_& value,
                const T_& value1,
                const T_& value2,
                float duration,
                typename Easing<T_>::Function easingFunction,
                void* data = nullptr) : FiniteAction(data),
                                        m_value(&value),
                                        m_interpolator(value1, value2, duration, easingFunction),
                                        m_timeElapsed(0.f)
        {
            GEM_ASSERT(easingFunction);
        }

        Tween(T_* value,
              const T_& value1,
              const T_& value2,
              float duration,
              typename Easing<T_>::Function easingFunction,
              void* data = nullptr) : FiniteAction(data),
                                      m_value(value),
                                      m_interpolator(value1, value2, duration, easingFunction),
                                      m_timeElapsed(0.f)
        {
            GEM_ASSERT(value);
            GEM_ASSERT(easingFunction);
        }

    public:
        virtual void Reset()
        {
            FiniteAction::Reset();

            m_timeElapsed = 0.f;
        }

        virtual void Update(float aTimeDelta)
        {
            if (!Finished())
            {
                m_timeElapsed += aTimeDelta;

                if (!m_interpolator.interpolate(*m_value, m_timeElapsed))
                {
                    GEM_ASSERT((*m_value == m_interpolator.Value1())
                                || (*m_value == m_interpolator.Value2()));
                    m_timeElapsed = m_interpolator.Duration();
                    Finish();
                }
            }
        }

        virtual ActionPtr Reversed() const
        {
            ActionPtr reversed(new Tween<T_>(m_value,
                                m_interpolator.Value2(),
                                m_interpolator.Value1(),
                                m_interpolator.Duration(),
                                m_interpolator.EasingFunction(),
                                Data()));

            return reversed;
        }

    public:
        virtual float Duration() const
        {
            return m_interpolator.Duration();
        }

        virtual float TimeElapsed() const
        {
            return m_timeElapsed;
        }

    public:
        T_& Value()
        {
            GEM_ASSERT(m_value);

            return m_value;
        }

        const T_& Value() const
        {
            GEM_ASSERT(m_value);

            return m_value;
        }

        void SetValue(T_& value)
        {
            m_value = value;
        }

        void SetValue(T_* value)
        {
            GEM_ASSERT(value);

            m_value = value;
        }

        Gem::Interpolator<T_>& Interpolator()
        {
            return m_interpolator;
        }

        const Gem::Interpolator<T_>& Interpolator() const
        {
            return m_interpolator;
        }

    private:
        T_* m_value;
        Gem::Interpolator<T_> m_interpolator;
        float m_timeElapsed;
    };
}

#endif //GEM_TWEEN_HPP
