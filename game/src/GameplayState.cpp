#include "GameplayState.hpp"

#include <iostream>
#include <gem/Content.hpp>
#include <gem/detail/SdlGraphics.hpp>

namespace Deadstorm
{
    GameplayState::GameplayState()
    {}

    GameplayState::~GameplayState()
    { }

    void GameplayState::OnEnter(void *owner, int previousStateId)
    {
        puts("GamePlayState::OnEnter");
        m_grass = g_content.Acquire<Gem::Texture>("assets/image/grass.jpg");
    }

    void GameplayState::OnExit(void *owner, int nextStateId)
    {
        puts("GamePlayState::OnExit");
    }

    void GameplayState::OnSuspend(void *owner, int pushedStateId)
    { }

    void GameplayState::OnResume(void *owner, int poppedStateId)
    { }

    void GameplayState::OnUpdate(float dt, bool suspended)
    {}

    void GameplayState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.DrawTexture(*m_grass);
    }

    void GameplayState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void GameplayState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == 0)
        {
            std::cout << input.which() << std::endl;
        }
    }
}