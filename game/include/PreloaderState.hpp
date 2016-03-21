#ifndef DEADSTORM_PRELOADERSTATE_HPP
#define DEADSTORM_PRELOADERSTATE_HPP

#include <gem/TexturePart.hpp>
#include "gem/GameState.hpp"

namespace Deadstorm
{
    class PreloaderState : public Gem::GameState
    {
    public:
        PreloaderState();
        virtual ~PreloaderState();

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
    };
}

#endif //DEADSTORM_PRELOADERSTATE_HPP
