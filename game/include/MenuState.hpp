#ifndef DEADSTORM_MENUSTATE_HPP
#define DEADSTORM_MENUSTATE_HPP


#include <gem/Texture.hpp>
#include "gem/GameState.hpp"

namespace Deadstorm
{
    class MenuState : public Gem::GameState
    {
    public:
        virtual void OnEnter(void* owner, int previousStateId) override;
        virtual void OnExit(void* owner, int nextStateId) override;
        virtual void OnSuspend(void* owner, int pushedStateId) override;
        virtual void OnResume(void* owner, int poppedStateId) override;

    public:
        virtual void OnUpdate(float dt, bool suspended) override;
        virtual void OnDraw(Gem::Graphics& graphics, bool suspended) override;
        virtual void OnEvent(const Gem::Event& event, bool suspended) override;
        virtual void OnInput(const Gem::Input& input, bool suspended) override;

    private:
        Gem::TexturePtr m_bg;
    };

}

#endif //DEADSTORM_MENUSTATE_HPP
