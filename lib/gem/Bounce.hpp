#ifndef GEM_BOUNCE_HPP
#define GEM_BOUNCE_HPP

#include "gem/FiniteAction.hpp"

namespace Gem
{
    class Bounce : public FiniteAction
    {
    public:
        Bounce(FiniteActionPtr action, int bounceCount = 1, void* data= nullptr) : FiniteAction(data),
                                                                                   m_action(action),
                                                                                   m_reverseAction(nullptr),
                                                                                   m_bounceCount(bounceCount),
                                                                                   m_bounceCounter(0),
                                                                                   m_reverseActionActive(false)
        {
            GEM_ASSERT(action);
            GEM_ASSERT(bounceCount >= 0);

            m_reverseAction = std::dynamic_pointer_cast<FiniteAction>(action->Reversed());
        }

    public:
        virtual void Reset();
        virtual void Update(float aTimeDelta);
        virtual ActionPtr Reversed() const;

    public:
        virtual float Duration() const;
        virtual float TimeElapsed() const;

    public:
        FiniteActionPtr Action()
        {
            return m_action;
        }

        ConstFiniteActionPtr Action() const
        {
            return m_action;
        }

        FiniteActionPtr ReverseAction()
        {
            return m_reverseAction;
        }

        ConstFiniteActionPtr ReverseAction() const
        {
            return m_reverseAction;
        }

    private:
        FiniteActionPtr m_action;
        FiniteActionPtr m_reverseAction;
        const int m_bounceCount;
        int m_bounceCounter;
        bool m_reverseActionActive;
    };
}


#endif //GEM_BOUNCE_HPP
