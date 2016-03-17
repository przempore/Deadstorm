#ifndef GEM_STATEMACHINE_HPP
#define GEM_STATEMACHINE_HPP

#include "gem/Assert.hpp"
#include "gem/Stack.hpp"
#include "gem/State.hpp"

#include <map>

namespace Gem
{
    class StateMachine
    {
    public:
        typedef Stack<StatePtr> StatePtrStack;

    public:
        inline StateMachine(void* owner, int idleStateId);

    public:
        inline void* Owner();
        inline const void* Owner() const;
        inline void SetOwner(void* owner);
        inline StatePtr State(int stateId);
        inline ConstStatePtr State(int stateId) const;
        const int* StateId(StatePtr state) const;
        inline StatePtr CurrentState();
        inline ConstStatePtr CurrentState() const;
        inline int CurrentStateId() const;
        inline int IdleStateId() const;
        inline StatePtrStack& StateStack();
        inline const StatePtrStack& StateStack() const;

    public:
        inline void Register(int stateId, StatePtr state);
        inline bool Registered(int stateId) const;
        inline bool Registered(StatePtr state) const;
        void ChangeState(int stateId);
        void PushState(int stateId);
        void PopState();
        inline void PopAllStates();

    private:
        typedef std::map<int, StatePtr> StatePtrMap;
        typedef StatePtrMap::iterator StatePtrMapIter;
        typedef StatePtrMap::const_iterator StatePtrMapConstIter;

    private:
        void* m_owner;
        StatePtrStack m_stateStack;
        StatePtrMap m_states;
        int m_currentStateId;
        int m_idleStateId;
    };
}

#include "gem/StateMachine.inl"

#endif //GEM_STATEMACHINE_HPP