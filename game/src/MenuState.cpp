#include <Defines.hpp>
#include <gem/GameStateManager.hpp>
#include "MenuState.hpp"

#include <iostream>
#include <gem/Graphics.hpp>
#include <gem/Content.hpp>

namespace Deadstorm
{
    MenuState::MenuState()
    {}

    MenuState::~MenuState()
    { }

    void MenuState::OnEnter(void *owner, int previousStateId)
    {
        puts("MenuState::OnEnter");
        m_bg = g_content.Acquire<Gem::Texture>("assets/image/menu_bg.png");
    }

    void MenuState::OnExit(void *owner, int nextStateId)
    {
        puts("MenuState::OnExit");
    }

    void MenuState::OnSuspend(void *owner, int pushedStateId)
    { }

    void MenuState::OnResume(void *owner, int poppedStateId)
    { }

    void MenuState::OnUpdate(float dt, bool suspended)
    {}

    void MenuState::OnDraw(Gem::Graphics &graphics, bool suspended)
    {
        graphics.DrawTexture(*m_bg);
    }

    void MenuState::OnEvent(const Gem::Event &event, bool suspended)
    { }

    void MenuState::OnInput(const Gem::Input &input, bool suspended)
    {
        std::cout << input.which() << std::endl;
        if (input.which() == 1)
        {
            const Gem::TouchInput* touchInput = &boost::get<Gem::TouchInput>(input);
            std::cout << "point: " << touchInput->m_point.m_x << ", " << touchInput->m_point.m_y << std::endl;
            if (touchInput->m_point.m_x > 400
                    && touchInput->m_point.m_y > 400)
            {
                g_gameStateManager.ChangeState(GameStateId_GamePlay);
            }
        }
    }
}
