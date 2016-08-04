#include <gem/GameStateManager.hpp>
#include "PreloaderState.hpp"

#include <iostream>
#include <Defines.hpp>
#include <gem/Content.hpp>
#include <gem/Texture.hpp>

namespace Deadstorm
{
    void PreloaderState::OnEnter(void *owner, int previousStateId)
    {
        puts("PreloaderState::OnEnter");
        g_content.Register("jpg", Gem::Texture::Load);
        g_gameStateManager.ChangeState(g_gameStateId_Menu);
    }

    void PreloaderState::OnExit(void *owner, int nextStateId)
    {
        puts("PreloaderState::OnExit");
    }

    void PreloaderState::OnSuspend(void *owner, int pushedStateId)
    { }

    void PreloaderState::OnResume(void *owner, int poppedStateId)
    { }

    void PreloaderState::OnUpdate(float dt, bool suspended)
    {}

    void PreloaderState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {

    }

    void PreloaderState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void PreloaderState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == 0)
        {
            std::cout << input.which() << std::endl;
            g_gameStateManager.ChangeState(g_gameStateId_Menu);
        }
    }
}
