#ifndef DEADSTORM_DEADSTORM_HPP
#define DEADSTORM_DEADSTORM_HPP

#include <gem/Game.hpp>

namespace Deadstorm
{
    class Deadstorm : public Gem::Game
    {
    public:
        Deadstorm(int idleStateId);
        virtual ~Deadstorm();

    public:
        virtual void OnStartup() override;
        virtual void OnShutdown() override;
    };
}


#endif //DEADSTORM_DEADSTORM_HPP
