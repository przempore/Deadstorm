#include "gem/Sequence.hpp"

#include <algorithm>

namespace Gem
{
    void Sequence::Reset()
    {
        FiniteAction::Reset();

        std::for_each(m_actions.begin(),
                      m_actions.end(),
                      [](FiniteActionPtr action) {
                          action->Reset();
                      });

        m_activeActionIndex = 0;
    }

    void Sequence::Update(float aTimeDelta)
    {
        if (m_actions.empty())
            Finish();

        if (Finished())
            return;

        if (UpdateInstatActions(aTimeDelta))
        {
            Finish();
            return;
        }

        GEM_ASSERT(m_actions[m_activeActionIndex]->Interval());

        m_actions[m_activeActionIndex]->Update(aTimeDelta);

        if (m_actions[m_activeActionIndex]->Finished())
        {
            ++m_activeActionIndex;

            if (m_activeActionIndex == m_actions.size())
                Finish();
        }
    }

    ActionPtr Sequence::Reversed() const
    {
        SequencePtr reversed(new Sequence());

        std::for_each(m_actions.rbegin(), m_actions.rend(), [&reversed](FiniteActionPtr action) {
            reversed->Actions().push_back(std::dynamic_pointer_cast<FiniteAction>(action->Reversed()));
        });

        return reversed;
    }

    float Sequence::Duration() const
    {
        float duration = 0.f;
        for (size_t i = 0; i < m_actions.size(); ++i)
            duration += m_actions[i]->Duration();

        return duration;
    }

    float Sequence::TimeElapsed() const
    {
        float timeElapsed = 0.f;

        for (size_t i = 0; i < m_activeActionIndex; ++i)
            timeElapsed += m_actions[i]->Duration();

        if (!m_actions.empty())
        {
            GEM_ASSERT((m_activeActionIndex >= 0) && (m_activeActionIndex < m_actions.size()));

            timeElapsed += m_actions[m_activeActionIndex]->TimeElapsed();
        }

        return timeElapsed;
    }

    void Sequence::SkipActiveAction()
    {
        ++m_activeActionIndex;

        if (m_activeActionIndex == m_actions.size())
            Finish();
    }

    bool Sequence::UpdateInstatActions(float aTimeDelta)
    {
        GEM_ASSERT(m_actions.size() > 0);
        GEM_ASSERT(m_activeActionIndex < m_actions.size());

        while (m_actions[m_activeActionIndex]->Instant())
        {
            m_actions[m_activeActionIndex]->Update(aTimeDelta);

            ++m_activeActionIndex;

            if (m_activeActionIndex == m_actions.size())
                return true;
        }

        return false;
    }
}
