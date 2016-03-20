#include "GamePlayState.hpp"

#include <iostream>
#include <gem/Content.hpp>
#include <gem/detail/SdlGraphics.hpp>

class GraphicsPtr;
namespace Deadstorm
{
    GamePlayState::GamePlayState()
    {}

    GamePlayState::~GamePlayState()
    { }

    void GamePlayState::OnEnter(void *owner, int previousStateId)
    {
        puts("GamePlayState::OnEnter");
        g_content.Register("jpg", Gem::Texture::Load);
        m_grass = g_content.Acquire<Gem::Texture>("assets/image/grass.jpg");
    }

    void GamePlayState::OnExit(void *owner, int nextStateId)
    {
        puts("GamePlayState::OnExit");
    }

    void GamePlayState::OnSuspend(void *owner, int pushedStateId)
    { }

    void GamePlayState::OnResume(void *owner, int poppedStateId)
    { }

    void GamePlayState::OnUpdate(float dt, bool suspended)
    {}

    void GamePlayState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.DrawTexture(*m_grass);
    }

    void GamePlayState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void GamePlayState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == 0)
        {
            std::cout << input.which() << std::endl;
        }
    }
}