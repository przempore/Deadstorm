#ifndef GEM_SEQUENCE_HPP
#define GEM_SEQUENCE_HPP

#include "gem/FiniteAction.hpp"

#include <vector>

namespace Gem
{
    class Sequence;

    typedef std::shared_ptr<Sequence> SequencePtr;
    typedef std::weak_ptr<Sequence> SequenceWPtr;
    typedef std::shared_ptr<const Sequence> ConstSequencePtr;
    typedef std::weak_ptr<const Sequence> ConstSequenceWPtr;

    class Sequence : public FiniteAction
    {
    public:
        typedef std::vector<FiniteActionPtr> FiniteActionPtrArray;

    public:
        Sequence() : m_activeActionIndex(0)
        {}

    public:
        virtual void Reset();
        virtual void Update(float aTimeDelta);
        virtual ActionPtr Reversed() const;

    public:
        virtual float Duration() const;
        virtual float TimeElapsed() const;

    public:
        FiniteActionPtrArray& Actions()
        {
            return m_actions;
        }

        const FiniteActionPtrArray& Actions() const
        {
            return m_actions;
        }

        FiniteActionPtr ActiveAction()
        {
            return m_actions[m_activeActionIndex];
        }

        ConstFiniteActionPtr ActiveAction() const
        {
            return m_actions[m_activeActionIndex];
        }

        int ActiveActionIndex() const
        {
            return m_activeActionIndex;
        }

    public:
        void SkipActiveAction();

    private:
        bool UpdateInstatActions(float aTimeDelta);

    private:
        FiniteActionPtrArray m_actions;
        size_t m_activeActionIndex;
    };
}


#endif //GEM_SEQUENCE_HPP
