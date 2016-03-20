#ifndef GEM_REPEAT_HPP
#define GEM_REPEAT_HPP

#include "FiniteAction.hpp"

namespace Gem
{
    class Repeat : public FiniteAction
    {
    public:
        Repeat(FiniteActionPtr action,
        int repeatCount,
        void* data = nullptr) : FiniteAction(data),
                                m_action(action),
                                m_repeatCount(repeatCount),
                                m_repeatCounter(0)
        {
            GEM_ASSERT(action);
            GEM_ASSERT(repeatCount >= 0);
        }

    public:
        virtual void Reset();
        virtual void Update(float aTimeData);
        virtual ActionPtr Reversed() const;

    public:
        virtual float Duration() const;
        virtual float TimeElapsed() const;

    private:
        FiniteActionPtr m_action;
        const int m_repeatCount;
        int m_repeatCounter;
    };
}


#endif //GEM_REPEAT_HPP
