#ifndef DEADSTORM_GAMEPLAYSTATE_HPP
#define DEADSTORM_GAMEPLAYSTATE_HPP

#include <gem/Texture.hpp>
#include <gem/TexturePart.hpp>
#include "gem/GameState.hpp"
#include "AnimSprite.hpp"

namespace Deadstorm
{
    class GameplayState : public Gem::GameState
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
        Gem::ConstTexturePtr m_grass;
        Gem::Rectangle m_rexMovingRect;
        AnimSpritePtr m_rex;
    };

}

#endif //DEADSTORM_GAMEPLAYSTATE_HPP
