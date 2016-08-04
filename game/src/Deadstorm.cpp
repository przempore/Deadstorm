#include "Deadstorm.hpp"
#include "Defines.hpp"

#include <gem/GameStateManager.hpp>
#include "PreloaderState.hpp"
#include "MenuState.hpp"
#include "GameplayState.hpp"

namespace Deadstorm
{
    Deadstorm::Deadstorm(int idleStateId) : Gem::Game(idleStateId)
    {
    }

    Deadstorm::~Deadstorm()
    {
    }

    void Deadstorm::OnStartup()
    {
        Gem::GameStatePtr preloaderState(new PreloaderState());
        Gem::GameStatePtr menuState(new MenuState());
        Gem::GameStatePtr gamePlayState(new GameplayState());

        g_gameStateManager.Register(g_gameStateId_Preloader, preloaderState);
        g_gameStateManager.Register(g_gameStateId_Menu, menuState);
        g_gameStateManager.Register(g_gameStateId_GamePlay, gamePlayState);

        g_gameStateManager.PushState(g_gameStateId_Preloader);
    }

    void Deadstorm::OnShutdown()
    {

    }
}

namespace Gem
{
    ApplicationPtr CreateApplication()
    {
        return ApplicationPtr(new Deadstorm::Deadstorm(Deadstorm::g_gameStateId_Creation));
    }
}