#include "Deadstorm.hpp"
#include "Defines.hpp"

#include <gem/GameStateManager.hpp>
#include "PreloaderState.hpp"
#include "MenuState.hpp"
#include "GamePlayState.hpp"

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
        Gem::GameStatePtr gamePlayState(new GamePlayState());

        g_gameStateManager.Register(GameStateId_Preloader, preloaderState);
        g_gameStateManager.Register(GameStateId_Menu, menuState);
        g_gameStateManager.Register(GameStateId_GamePlay, gamePlayState);

        g_gameStateManager.PushState(GameStateId_Preloader);
    }

    void Deadstorm::OnShutdown()
    {

    }
}

namespace Gem
{
    ApplicationPtr CreateApplication()
    {
        return ApplicationPtr(new Deadstorm::Deadstorm(0));
    }
}