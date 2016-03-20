#include "Application.hpp"

namespace Deadstorm
{
    void Application::OnStartup()
    {

    }

    void Application::OnShutdown()
    {

    }

    void Application::OnUpdate(float dt)
    {

    }

    void Application::OnDraw(Gem::Graphics &graphics)
    {

    }

    void Application::OnEvent(Gem::Event event)
    {

    }

    void Application::OnInput(Gem::Input input)
    {

    }
}

namespace Gem
{
    ApplicationPtr CreateApplication()
    {
        return ApplicationPtr(new Deadstorm::Application);
    }
}
