#include "Application.hpp"

namespace Game
{
    void Game::OnStartup()
    {

    }

    void Game::OnShutdown()
    {

    }

    void Game::OnUpdate(float dt)
    {

    }

    void Game::OnDraw(Gem::Graphics &graphics)
    {

    }

    void Game::OnEvent(Gem::Event event)
    {

    }

    void Game::OnInput(Gem::Input input)
    {

    }
}

namespace Gem
{
    ApplicationPtr CreateApplication()
    {
        return ApplicationPtr(new Game::Game);
    }
}
