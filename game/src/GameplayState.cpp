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
        m_grass = g_content.Acquire<Gem::Texture>("assets/image/grass.jpg", true);
        g_content.Register("xml", Gem::TexturePart::Load);

        m_rex.reset(new Actor("assets/textures.xml", 4, 3, 32, 40, 0, 0, true));
    }

    void GameplayState::OnExit(void *owner, int nextStateId)
    {
    }

    void GameplayState::OnSuspend(void *owner, int pushedStateId)
    {}

    void GameplayState::OnResume(void *owner, int poppedStateId)
    {}

    void GameplayState::OnUpdate(float dt, bool suspended)
    {
        if (m_rex->IsMoving())
        {
            m_rex->Move();
        }
    }

    void GameplayState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.Clear(Gem::Color::s_white);
        graphics.DrawTexture(*m_grass);
        graphics.DrawTexture(*m_rex->Texture(),
                             m_rex->SourceRectangle(),
                             &m_rex->Rectangle(),
                             Gem::Color::s_black);

        if (m_rex->IsMoving())
        {
            m_rex->Animate(m_rex->GetMovingAngle());
        }
    }

    void GameplayState::OnEvent(const Gem::Event &event, bool suspended)
    {}

    void GameplayState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == (int) Gem::InputType::TouchInput)
        {
            const Gem::TouchInput *touchInput = &boost::get<Gem::TouchInput>(input);
            if (touchInput->m_action == Gem::TouchAction::Down)
            {
                switch (touchInput->m_point.m_id)
                {
                    case 0:
                        m_rex->StartMovingTo(touchInput->m_point.m_x, touchInput->m_point.m_y);
                        break;
                    case 1:
                        m_rex->SetMoving(false);
                        m_rex->SetPosition(touchInput->m_point.m_x, touchInput->m_point.m_y);
                        break;

                    default:
                        std::cerr << "Wrong input type!!" << std::endl;
                }
            }
        }
    }
}
