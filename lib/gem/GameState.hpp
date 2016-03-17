#ifndef GEM_GAME_STATE_HPP
#define GEM_GAME_STATE_HPP

#include "gem/Event.hpp"
#include "gem/Input.hpp"
#include "gem/State.hpp"

#include <memory>

namespace Gem
{
	class Graphics;

	class GameState : public State
	{
	public:
		virtual void OnEnter(void* owner, int previousStateId) {}
		virtual void OnExit(void* owner, int nextStateId) {}
		virtual void OnSusprend(void* owner, int pushedStateId) {}
		virtual void OnResume(void* owner, int poppedStateId) {}

	public:
		virtual void OnUpdate(float dt, bool suspended) = 0;
		virtual void OnDraw(Graphics& graphics, bool suspended) = 0;
		virtual void OnEvent(const Event& event, bool suspended) = 0;
		virtual void OnInput(const Input& input, bool suspended) = 0;
	};
	typedef std::shared_ptr<GameState> GameStatePtr;
	typedef std::shared_ptr<const GameState> ConstGameStatePtr;
}

#endif //GEM_GAME_STATE_HPP