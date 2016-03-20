#include "Repeat.hpp"

namespace Gem
{
    void Repeat::Reset()
    {
        FiniteAction::Reset();

        m_action->Reset();
        m_repeatCounter = 0;
    }

    void Repeat::Update(float aTimeData)
    {
        if (m_repeatCount > 0)
        {
            if (!Finished())
            {
                m_action->Update(aTimeData);

                if (m_action->Finished())
                {
                    if (++m_repeatCounter < m_repeatCount)
                    {
                        m_action->Reset();
                    }
                    else
                    {
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

    ActionPtr Repeat::Reversed() const
    {
        return ActionPtr(
                new Repeat(
                        std::dynamic_pointer_cast<FiniteAction>(m_action->Reversed()), m_repeatCount));
    }

    float Repeat::Duration() const
    {
        return m_repeatCount * m_action->Duration();
    }

    float Repeat::TimeElapsed() const
    {
        return m_repeatCounter * m_action->Duration() + m_action->TimeElapsed();
    }
}