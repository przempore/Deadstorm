#ifndef GEM_GAME_STATE_MANAGER_HPP
#define GEM_GAME_STATE_MANAGER_HPP

#include "gem/Event.hpp"
#include "gem/GameState.hpp"
#include "gem/Input.hpp"
#include "gem/Singleton.hpp"
#include "gem/StateMachine.hpp"

namespace Gem
{
	class Graphics;

	class GameStateManager : public Singleton <GameStateManager>
	{
	friend class Game;

	public:
		inline GameStateManager(int idleStateId);

	public:
		inline GameStatePtr State(int stateId);
		inline ConstGameStatePtr State(int stateId) const;
		inline const int* StateId(GameStatePtr state) const;
		inline GameStatePtr CurrentState();
		inline ConstGameStatePtr CurrentState() const;
		inline int CurrentStateId() const;
		inline int IdleStateId() const;

	public:
		inline void Register(int stateId, GameStatePtr state);
		inline bool Registered(int stateId) const;
		inline bool Registered(GameStatePtr state) const;
		inline void ChangeState(int stateId);
		inline void PushState(int stateId);
		inline void PopState(int stateId);
		inline void PopAllStates();

	private:
		void OnUpdate(float dt);
		void OnDraw(Graphics& graphics);
		void OnEvent(const Event& event);
		void OnInput(const Input& input);

	private:
		StateMachine m_stateMachine;
	};
}

#define g_gameStateManager Gem::GameStateManager::Instance()

#include "gem/GameStateManager.inl"

#endif //GEM_GAME_STATE_MANAGER_HPP