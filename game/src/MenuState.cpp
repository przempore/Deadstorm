#include <Defines.hpp>
#include <gem/GameStateManager.hpp>
#include "MenuState.hpp"

#include <iostream>
#include <gem/Graphics.hpp>
#include <gem/Content.hpp>

namespace Deadstorm
{
    void MenuState::OnEnter(void *owner, int previousStateId)
    {
        m_bg = g_content.Acquire<Gem::Texture>("assets/image/menu_bg.png");
        g_gameStateManager.ChangeState(g_gameStateId_GamePlay);   // test
    }

    void MenuState::OnExit(void *owner, int nextStateId)
    {
    }

    void MenuState::OnSuspend(void *owner, int pushedStateId)
    { }

    void MenuState::OnResume(void *owner, int poppedStateId)
    { }

    void MenuState::OnUpdate(float dt, bool suspended)
    { }

    void MenuState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.DrawTexture(*m_bg);
    }

    void MenuState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void MenuState::OnInput(const Gem::Input &input, bool suspended)
    {
        if (input.which() == 1)
        {
            const Gem::TouchInput *touchInput = &boost::get<Gem::TouchInput>(input);
            if (touchInput->m_action == Gem::TouchAction::Down
                && touchInput->m_point.m_x > 400
                && touchInput->m_point.m_y > 400)
            {
                g_gameStateManager.ChangeState(g_gameStateId_GamePlay);
            }
        }
    }
}
