#include "Deadstorm.hpp"

namespace Deadstorm
{
    Deadstorm::Deadstorm(int idleStateId) : Gem::Game(idleStateId)
    {
    }

    Deadstorm::~Deadstorm()
    {
    }

    void Deadstorm::OnStartup()
    {
    }

    void Deadstorm::OnShutdown()
    {

    }
}

namespace Gem
{
    ApplicationPtr CreateApplication()
    {
        return ApplicationPtr(new Deadstorm::Deadstorm(1));
    }
}