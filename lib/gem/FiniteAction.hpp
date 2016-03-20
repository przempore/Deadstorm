#ifndef GEM_FINITEACTION_HPP
#define GEM_FINITEACTION_HPP

#include "gem/Action.hpp"
#include "gem/Signal.hpp"
#include "gem/Assert.hpp"

namespace Gem
{
    class FiniteAction;

    typedef std::shared_ptr<FiniteAction> FiniteActionPtr;
    typedef std::weak_ptr<FiniteAction> FiniteActionWPtr;
    typedef std::shared_ptr<const FiniteAction> ConstFiniteActionPtr;
    typedef std::weak_ptr<const FiniteAction> ConstFiniteActionWPtr;

    class FiniteAction : public Action
    {
        GEM_SIGNAL(Finished, (void*));

    public:
        FiniteAction(void* data = nullptr) : m_finished(false),
                                             m_data(data)
        {}

    public:
        virtual void Reset()
        {
            m_finished = false;
        }

    public:
        virtual float Duration() const = 0;
        virtual float TimeElapsed() const = 0;

    public:
        float TimeLeft() const
        {
            float duration = Duration();
            float timeElapsed = TimeElapsed();

            GEM_ASSERT(duration >= timeElapsed);

            return duration - timeElapsed;
        }

        bool Finished() const
        {
            return m_finished;
        }

        bool Instant() const
        {
            float duration = Duration();

            GEM_ASSERT(duration >= 0.f);

            return duration == 0.f;
        }

        bool Interval() const
        {
            float duration = Duration();

            GEM_ASSERT(duration >= 0.f);

            return duration > 0.f;
        }

    public:
        void* Data() const
        {
            return m_data;
        }

        void SetData(void* data)
        {
            m_data = data;
        }

    protected:
        void SetFinished(bool finished)
        {
            m_finished = finished;
        }

        void Finish()
        {
            SetFinished(true);
            GEM_EMIT(Finished, (Data()));
        }

    private:
        bool m_finished;
        void* m_data;
    };
}

#endif //GEM_FINITEACTION_HPP
