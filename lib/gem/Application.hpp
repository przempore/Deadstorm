#ifndef GEM_APPLICATION_HPP
#define GEM_APPLICATION_HPP

#include "gem/Event.hpp"
#include "gem/Input.hpp"
#include "gem/Singleton.hpp"

#include <memory>

namespace Gem
{
	class Graphics;

	class Application : public Singleton< Application >
	{
	public:
		virtual void OnStartup()  = 0;
		virtual void OnShutdown() = 0;
		virtual void OnUpdate( float dt ) = 0;
		virtual void OnDraw( Graphics& graphics ) = 0;
		virtual void OnEvent( Event event ) = 0;
		virtual void OnInput( Input input ) = 0;

	public:
		void Quit();
	};

	typedef std::unique_ptr< Application > ApplicationPtr;
};

#define g_application Application::Instance()

#endif // ifndef GEM_APPLICATION_HPP
