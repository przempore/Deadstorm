#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "gem/Application.hpp"

namespace Deadstorm
{
	class Application : public Gem::Application
	{

	public:
		virtual void OnStartup() override;
		virtual void OnShutdown() override;
		virtual void OnUpdate(float dt) override;
		virtual void OnDraw(Gem::Graphics &graphics) override;
		virtual void OnEvent(Gem::Event event) override;
		virtual void OnInput(Gem::Input input) override;
	};
}

#endif //APPLICATION_HPP
