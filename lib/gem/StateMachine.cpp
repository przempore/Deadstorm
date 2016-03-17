#include "gem/StateMachine.hpp"

namespace Gem
{
    const int *StateMachine::StateId(StatePtr state) const
    {
	    StatePtrMapConstIter it(m_states.begin());
		StatePtrMapConstIter end(m_states.end());

	    for (; it != end; ++it)
	    {
		    if (it->second == state)
		    {
			    return &it->first;
		    }
	    }
	    return NULL;
    }

    void StateMachine::ChangeState(int stateId)
    {
	    GEM_ASSERT(stateId != m_idleStateId);
	    GEM_ASSERT(m_stateStack.Size() > 0);
	    GEM_ASSERT(Registered(stateId));

	    StatePtr currentState(m_stateStack.Top());
	    GEM_ASSERT(currentState);

	    currentState->OnExit(m_owner, stateId);

	    StatePtr nextState(State(stateId));
	    GEM_ASSERT(nextState);

	    int praviousStateId = m_currentStateId;

	    m_currentStateId = stateId;
	    m_stateStack.Top() = nextState;

	    nextState->OnEnter(m_owner, praviousStateId);
    }

    void StateMachine::PushState(int stateId)
    {
	    GEM_ASSERT(stateId != m_idleStateId);
	    GEM_ASSERT(Registered(stateId));

	    StatePtr currentState(CurrentState());

	    if (currentState)
	    {
		    currentState->OnSuspend(m_owner, stateId);
	    }

	    StatePtr nextState = State(stateId);
	    GEM_ASSERT(nextState);

	    int previousStateId = m_currentStateId;
	    m_currentStateId = stateId;

	    m_stateStack.Push(nextState);
	    nextState->OnEnter(m_owner, previousStateId);
    }

    void StateMachine::PopState()
    {
	    GEM_ASSERT(m_stateStack.Size() > 0);

	    StatePtr currentState = m_stateStack.Top();
	    GEM_ASSERT(currentState);

	    int resumedStateId = (m_stateStack.Size() > 1)
	                         ? *StateId(m_stateStack[m_stateStack.Size() - 2]) : m_idleStateId;

	    currentState->OnExit(m_owner, resumedStateId);

	    m_stateStack.Pop();

	    int poppedStateId = m_currentStateId;
	    m_currentStateId = resumedStateId;

	    if (m_currentStateId != m_idleStateId)
	    {
		    StatePtr resumedState = m_stateStack.Top();
		    GEM_ASSERT(resumedState);

		    resumedState->OnResume(m_owner, poppedStateId);
	    }
	    else
	    {
		    GEM_ASSERT(m_stateStack.Empty());
	    }
    }
}