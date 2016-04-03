#include "GameplayState.hpp"

#include <iostream>
#include <gem/Content.hpp>
#include <gem/detail/SdlGraphics.hpp>
#include <gem/Error.hpp>
#include <gem/Color.hpp>

namespace Deadstorm
{
    void GameplayState::OnEnter(void *owner, int previousStateId)
    {
        puts("GamePlayState::OnEnter");
        m_grass = g_content.Acquire<Gem::Texture>("assets/image/grass.jpg", true);
        g_content.Register("xml", Gem::TexturePart::Load);

        m_rex.reset(new AnimSprite("assets/textures.xml", 4, 3, true));
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
    { }

    void GameplayState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.Clear(Gem::Color::s_white);
        graphics.DrawTexture(*m_grass);
        graphics.DrawTexture(*m_rex->Texture(),
                             m_rex->SourceRectangle(),
                             &m_rex->Rectangle(),
                             Gem::Color::s_black);
    }

    void GameplayState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void GameplayState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == 1)
        {
            const Gem::TouchInput *touchInput = &boost::get<Gem::TouchInput>(input);
            if (touchInput->m_action == Gem::TouchAction::Down)
            {
                m_rex->SetPlace(touchInput->m_point.m_x, touchInput->m_point.m_y);
            }
        }
    }
}