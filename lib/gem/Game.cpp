#include "gem/Game.hpp"

#include "gem/GameState.hpp"
#include "gem/GameStateManager.hpp"

namespace Gem
{
    Game::Game(int idleStateId) : m_gameStateManager(new GameStateManager(idleStateId))
    {

    }

    Game::~Game()
    {
        delete m_gameStateManager;
    }

    void Game::OnUpdate(float dt)
    {
        m_gameStateManager->OnUpdate(dt);
    }

    void Game::OnDraw(Graphics &graphics)
    {
        m_gameStateManager->OnDraw(graphics);
    }

    void Game::OnEvent(const Event& event)
    {
        m_gameStateManager->OnEvent(event);
    }

    void Game::OnInput(const Input& input)
    {
        m_gameStateManager->OnInput(input);
    }
}