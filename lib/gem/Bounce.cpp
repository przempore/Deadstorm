#include "gem/Bounce.hpp"

namespace Gem
{
    void Bounce::Reset()
    {
        FiniteAction::Reset();

        m_action->Reset();
        m_reverseAction->Reset();
        m_bounceCounter = 0;
        m_reverseActionActive = false;
    }

    void Bounce::Update(float aTimeDelta)
    {
        if (m_bounceCount > 0)
        {
            if (!Finished())
            {
                if (!m_reverseActionActive)
                {
                    m_action->Update(aTimeDelta);

                    if (m_action->Finished())
                    {
                        m_action->Reset();
                        m_reverseActionActive = true;
                    }
                }
                else
                {
                    m_reverseAction->Update(aTimeDelta);

                    if (m_reverseAction->Finished())
                    {
                        if (++m_bounceCounter < m_bounceCount)
                        {
                            m_reverseAction->Reset();
                            m_reverseActionActive = false;
                        }
                        else
                            Finish();
                    }
                }
            }
        }
        else
        {
            if (!Finished())
                Finish();
        }
    }

    ActionPtr Bounce::Reversed() const
    {
        ActionPtr reversed(
                new Bounce(std::dynamic_pointer_cast<FiniteAction>(m_action->Reversed()),m_bounceCount));
        GEM_ASSERT(reversed);

        return reversed;
    }

    float Bounce::Duration() const
    {
        return m_bounceCount * m_action->Duration() + m_bounceCount * m_reverseAction->Duration();
    }

    float Bounce::TimeElapsed() const
    {
        return m_bounceCount
        * m_action->Duration()
        + m_bounceCount
        * m_reverseAction->Duration()
        + (m_reverseActionActive
          ? m_action->Duration()
            + m_reverseAction->TimeElapsed()
          : m_action->TimeElapsed());
    }
}
