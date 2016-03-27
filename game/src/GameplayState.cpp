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
        try
        {
            m_rex = g_content.Acquire<Gem::TexturePart>("assets/textures.xml", true);
        }
        catch (Gem::Error er)
        {
            std::cerr << er.What() << std::endl;
        }
        m_rexMovingRect = {m_rex->SourceRectangle().m_x,
                     m_rex->SourceRectangle().m_y,
                     m_rex->SourceRectangle().m_width / 2,
                     m_rex->SourceRectangle().m_height / 3};
        m_rex->SourceRectangle().Reset(1 * (m_rex->SourceRectangle().m_width / 3),
                                       1 * (m_rex->SourceRectangle().m_height / 4),
                                       m_rex->SourceRectangle().m_width / 3,
                                       m_rex->SourceRectangle().m_height / 4);

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
        if (!wasShowed)
        {
            printf("wymiary: %dx%d", m_rex->SourceRectangle().m_width, m_rex->SourceRectangle().m_height);
            wasShowed = true;
        }

        graphics.Clear(Gem::Color::s_white);
        graphics.DrawTexture(*m_grass);
        graphics.DrawTexture(*m_rex->Texture(),
                             m_rex->SourceRectangle(),
                             &m_rexMovingRect,
                             Gem::Color::s_black);
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