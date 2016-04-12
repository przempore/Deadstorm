#ifndef GEM_GAME_HPP
#define GEM_GAME_HPP

#include "gem/Application.hpp"

namespace Gem
{
    class GameStateManager;
    class Graphics;

    class Game : public Application
    {
    public:
        Game(int idleStateId);
        virtual ~Game();

    public:
        virtual void OnStartup() = 0;
        virtual void OnShutdown() = 0;

    public:
        virtual void OnUpdate(float dt) final;
        virtual void OnDraw(Graphics& graphics) final;
        virtual void OnEvent(const Event& event) final;
        virtual void OnEvent(Event event) final;
        virtual void OnInput(Input input) final;
        virtual void OnInput(const Input& input) final;

    private:
        GameStateManager* m_gameStateManager;
    };
}

#endif //GEM_GAME_HPP