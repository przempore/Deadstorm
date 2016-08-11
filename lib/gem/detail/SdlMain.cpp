#include "gem/Application.hpp"

#include "gem/Content.hpp"
#include "gem/Logger.hpp"

#include "gem/detail/SdlGraphics.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#if defined( _DEBUG )
# include <crtdbg.h>
#endif

namespace Gem
{
    SDL_Renderer *g_sdlRenderer{
            nullptr
    };

    namespace Detail
    {
        namespace
        {
            const char *g_applicationName{
                    "Deadstorm"
            };

            const int g_screenWidth{
                    960
            };
            const int g_screenHeight{
                    640
            };

            SDL_Window *g_sdlWindow{
                    nullptr
            };

            bool Startup()
            {
                if (SDL_Init(SDL_INIT_VIDEO) < 0)
                {
                    return false;
                }

                SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
                SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

                if ((g_sdlWindow = SDL_CreateWindow(g_applicationName,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    g_screenWidth,
                                                    g_screenHeight,
                                                    SDL_WINDOW_SHOWN)) == nullptr)
                {
                    return false;
                }

                if ((g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow,
                                                        -1,
                                                        SDL_RENDERER_ACCELERATED)) == nullptr)
                {
                    return false;
                }

                int flags{
                        IMG_INIT_PNG
                };

                if (!(IMG_Init(flags) & flags))
                {
                    printf("IMG_Init fail: %s", SDL_GetError());
                    return false;
                }

                if (TTF_Init() == -1)
                {
                    return false;
                }

                return true;
            }

            void Shutdown()
            {
                IMG_Quit();
                TTF_Quit();

                SDL_DestroyRenderer(g_sdlRenderer);
                g_sdlRenderer = nullptr;

                SDL_DestroyWindow(g_sdlWindow);
                g_sdlWindow = nullptr;

                SDL_Quit();
            }

        }
    }

    extern ApplicationPtr CreateApplication();
}

int main(int argv, char **argc)
{
#if defined( _DEBUG )
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    if (!Gem::Detail::Startup())
    {
        return EXIT_FAILURE;
    }

    typedef std::unique_ptr<Gem::Logger> LoggerPtr;

    LoggerPtr logger{
            new Gem::Logger
    };

    Gem::ApplicationPtr application{
            Gem::CreateApplication()
    };

    typedef std::unique_ptr<Gem::Content> ContentPtr;

    ContentPtr content{
            new Gem::Content
    };

    application->OnStartup();

    typedef std::unique_ptr<Gem::Graphics> GraphicsPtr;

    GraphicsPtr graphics{
            new Gem::SdlGraphics
    };

    SDL_Event event;

    Uint32 time1{
            SDL_GetTicks()
    };
    Uint32 time2{
            0
    };

    bool quit{
            false
    };

    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    quit = true;
                }
                    break;

                case SDL_KEYDOWN:
                {
                    Gem::KeyboardInput input;

                    input.m_state = Gem::KeyState::Down;
                    input.m_code = event.key.keysym.sym;

                    application->OnInput(Gem::Input(input));
                }
                    break;

                case SDL_KEYUP:
                {
                    Gem::KeyboardInput input;

                    input.m_state = Gem::KeyState::Up;
                    input.m_code = event.key.keysym.sym;

                    application->OnInput(Gem::Input(input));
                }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                {
                    Gem::TouchInput input;

                    SDL_GetMouseState(&input.m_point.m_x, &input.m_point.m_y);
                    input.m_action = Gem::TouchAction::Down;

                    event.button.button == SDL_BUTTON_LEFT
                        ? input.m_point.m_id = 0
                        : input.m_point.m_id = 1;

                    application->OnInput(Gem::Input(input));
                }
                    break;

                case SDL_MOUSEBUTTONUP:
                {
                    Gem::TouchInput input;

                    SDL_GetMouseState(&input.m_point.m_x, &input.m_point.m_y);
                    input.m_action = Gem::TouchAction::Up;

                    event.button.button == SDL_BUTTON_LEFT
                    ? input.m_point.m_id = 0
                    : input.m_point.m_id = 1;

                    application->OnInput(Gem::Input(input));
                }
                    break;
                case SDL_MOUSEMOTION:
                {
                    Gem::TouchInput input;

                    SDL_GetMouseState(&input.m_point.m_x, &input.m_point.m_y);
                    input.m_action = Gem::TouchAction::Move;

                    application->OnInput(Gem::Input(input));
                }
                    break;
                default:
                {
                }
                    break;
            } // switch
        }

        time2 = SDL_GetTicks();

        application->OnUpdate((time2 - time1) / 1000.f);
        application->OnDraw(*graphics);

        SDL_RenderPresent(Gem::g_sdlRenderer);

        time1 = time2;
    }

    application->OnShutdown();

    Gem::Detail::Shutdown();

    return EXIT_SUCCESS;
}
