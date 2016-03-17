namespace Gem
{
    inline StateMachine::StateMachine(void *owner, int idleStateId) : m_owner(owner),
                                                                      m_currentStateId(idleStateId),
                                                                      m_idleStateId(idleStateId)
    {
    }

    inline void *StateMachine::Owner()
    {
        return m_owner;
    }

    inline const void *StateMachine::Owner() const
    {
        return m_owner;
    }

    inline void StateMachine::SetOwner(void *owner)
    {
        m_owner = owner;
    }

    inline StatePtr StateMachine::State(int stateId)
    {
        return m_states[stateId];
    }

    inline ConstStatePtr StateMachine::State(int stateId) const
    {
        StatePtrMapConstIter found = m_states.find(stateId);

        if (found != m_states.end())
        {
            return found->second;
        }

        return ConstStatePtr();
    }

    inline StatePtr StateMachine::CurrentState()
    {
        if (m_stateStack.Size() > 0)
        {
            return m_stateStack.Top();
        }

        return StatePtr();
    }

    inline ConstStatePtr StateMachine::CurrentState() const
    {
        if (m_stateStack.Size() > 0)
        {
            return m_stateStack.Top();
        }

        return ConstStatePtr();
    }

    inline int StateMachine::CurrentStateId() const
    {
        return m_currentStateId;
    }

    inline int StateMachine::IdleStateId() const
    {
        return m_idleStateId;
    }

    inline StateMachine::StatePtrStack &StateMachine::StateStack()
    {
        return m_stateStack;
    }

    inline const StateMachine::StatePtrStack &StateMachine::StateStack() const
    {
        return m_stateStack;
    }

    inline void StateMachine::Register(int stateId, StatePtr state)
    {
        GEM_ASSERT(state);
        GEM_ASSERT(!Registered(stateId));
        GEM_ASSERT(!Registered(state));

        m_states[stateId] = state;
    }

    inline bool StateMachine::Registered(int stateId) const
    {
        return m_states.find(stateId) != m_states.end();
    }

    inline bool StateMachine::Registered(StatePtr state) const
    {
        return StateId(state) != NULL;
    }

    inline void StateMachine::PopAllStates()
    {
        m_stateStack.Clear();
    }
}