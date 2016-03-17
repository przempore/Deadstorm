#include "gem/GameStateManager.hpp"

namespace Gem
{
	void GameStateManager::OnUpdate(float dt)
	{
		for (int i = 0; i < m_stateMachine.StateStack().Size() - 1; ++i)
		{
			((Gem::GameState&)*m_stateMachine.StateStack()[i]).OnUpdate(dt, true);
		}

		if (m_stateMachine.StateStack().Size() > 0)
		{
			((Gem::GameState&)*m_stateMachine.StateStack().Top()).OnUpdate(dt, false);
		}
	}
	
	void GameStateManager::OnDraw(Graphics& graphics)
	{
		for (int i = 0; i < m_stateMachine.StateStack().Size() - 1; ++i)
		{
			((Gem::GameState&)*m_stateMachine.StateStack()[i]).OnDraw(graphics, true);
		}

		if (m_stateMachine.StateStack().Size() > 0)
		{
			((Gem::GameState&)*m_stateMachine.StateStack().Top()).OnDraw(graphics, false);
		}
	}

	void GameStateManager::OnEvent(const Event& event)
	{
		for (int i = 0; i < m_stateMachine.StateStack().Size() - 1; ++i)
		{
			((Gem::GameState&)*m_stateMachine.StateStack()[i]).OnEvent(event, true);
		}

		if (m_stateMachine.StateStack().Size() > 0)
		{
			((Gem::GameState&)*m_stateMachine.StateStack().Top()).OnEvent(event, false);
		}
	}

	void GameStateManager::OnInput(const Input& input)
	{
		for (int i = 0; i < m_stateMachine.StateStack().Size() - 1; ++i)
		{
			((Gem::GameState&)*m_stateMachine.StateStack()[i]).OnInput(input, true);
		}

		if (m_stateMachine.StateStack().Size() > 0)
		{
			((Gem::GameState&)*m_stateMachine.StateStack().Top()).OnInput(input, false);
		}
	}
}