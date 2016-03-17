namespace Gem
{
	inline GameStateManager::GameStateManager(int idleStateId) : m_stateMachine(nullptr, idleStateId)
	{
		m_stateMachine.SetOwner(this);
	}

	inline GameStatePtr GameStateManager::State(int stateId)
	{
		return std::dynamic_pointer_cast<GameState>(m_stateMachine.State(stateId));
	}

	inline ConstGameStatePtr GameStateManager::State(int stateId) const
	{
		return std::dynamic_pointer_cast<const GameState>(m_stateMachine.State(stateId));
	}

	inline const int* GameStateManager::StateId(GameStatePtr state) const
	{
		return m_stateMachine.StateId(state);
	}

	inline GameStatePtr GameStateManager::CurrentState()
	{
		return std::dynamic_pointer_cast<GameState>(m_stateMachine.CurrentState());
	}

	inline ConstGameStatePtr GameStateManager::CurrentState() const
	{
		return std::dynamic_pointer_cast<const GameState>(m_stateMachine.CurrentState());
	}

	inline int GameStateManager::CurrentStateId() const
	{
		return m_stateMachine.CurrentStateId();
	}

	inline int GameStateManager::IdleStateId() const
	{
		return m_stateMachine.IdleStateId();
	}

	inline void GameStateManager::Register(int stateId, GameStatePtr state)
	{
		m_stateMachine.Register(stateId, state);
	}

	inline bool GameStateManager::Registered(int stateId) const
	{
		return m_stateMachine.Registered(stateId);
	}

	inline bool GameStateManager::Registered(GameStatePtr state) const
	{
		return m_stateMachine.Registered(state);
	}

	inline void GameStateManager::ChangeState(int stateId)
	{
		m_stateMachine.ChangeState(stateId);
	}

	inline void GameStateManager::PushState(int stateId)
	{
		m_stateMachine.PushState(stateId);
	}

	inline void GameStateManager::PopState(int stateId)
	{
		m_stateMachine.PopState();
	}

	inline void GameStateManager::PopAllStates()
	{
		m_stateMachine.PopAllStates();
	}
}