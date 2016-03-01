#include "gem/Application.hpp"

#include <SDL.h>

namespace Gem
{
	void Application::Quit()
	{
		SDL_Event event;

		event.type = SDL_QUIT;
		SDL_PushEvent( &event );
	}

}
