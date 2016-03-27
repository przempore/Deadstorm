#include "gem/detail/SdlGraphics.hpp"

#include "gem/Assert.hpp"
#include "gem/Color.hpp"
#include "gem/Error.hpp"

#include "gem/detail/SdlTexture.hpp"

#include <SDL.h>
#include <gem/Rectangle.hpp>

namespace Gem
{
    extern SDL_Renderer *g_sdlRenderer;

    namespace
    {
        SDL_BlendMode BlendModeToSdlBlendMode(BlendMode blendMode)
        {
            switch (blendMode)
            {
                case BlendMode::None:
                    return SDL_BLENDMODE_NONE;
                case BlendMode::Additive:
                    return SDL_BLENDMODE_ADD;
                case BlendMode::AlphaBlend:
                    return SDL_BLENDMODE_BLEND;
                case BlendMode::Modulate:
                    return SDL_BLENDMODE_MOD;
            }

            GEM_ASSERT(!"dead code executed");

            return SDL_BLENDMODE_NONE;
        }

    }

    void SdlGraphics::Clear(const Color &color)
    {
        GEM_ASSERT(g_sdlRenderer);

        SDL_SetRenderDrawColor(g_sdlRenderer,
                               color.m_r,
                               color.m_g,
                               color.m_b,
                               color.m_a);
        SDL_RenderClear(g_sdlRenderer);

    }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  BlendMode blendMode)
    {
        GEM_ASSERT(g_sdlRenderer);

        if (SDL_SetRenderDrawBlendMode(g_sdlRenderer,
                                       BlendModeToSdlBlendMode(blendMode)) < 0)
        {
            throw Error{
                    SDL_GetError()
            };
        }

        const SdlTexture &sdlTexture{
                dynamic_cast< const SdlTexture & >( texture )
        };

        if (SDL_RenderCopy(g_sdlRenderer,
                           sdlTexture.Texture(),
                           nullptr,
                           nullptr))
        {
            throw Error{
                    SDL_GetError()
            };
        }
    }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Rectangle &destinationRectangle,
                                  const Color &color,
                                  BlendMode blendMode)
    {
        GEM_ASSERT(g_sdlRenderer);

        if (SDL_SetRenderDrawBlendMode(g_sdlRenderer,
                                       BlendModeToSdlBlendMode(blendMode)) < 0)
        {
            throw Error{
                    SDL_GetError()
            };
        }

        const SdlTexture &sdlTexture{
                dynamic_cast< const SdlTexture & >( texture )
        };

        SDL_SetRenderDrawColor(g_sdlRenderer, color.m_r, color.m_g, color.m_b, color.m_a);
//        SDL_RenderClear(g_sdlRenderer);

        int w = texture.Width();
        int h = texture.Height();
        SDL_QueryTexture(sdlTexture.Texture(), NULL, NULL, &w, &h);

        SDL_Rect rect;
        rect.h = destinationRectangle.m_height;
        rect.w = destinationRectangle.m_width;
        rect.x = destinationRectangle.m_x;
        rect.y = destinationRectangle.m_y;

        SDL_Rect crop;
        crop.h = destinationRectangle.m_height / 4;
        crop.w = destinationRectangle.m_width / 3;
        crop.x = destinationRectangle.m_x;
        crop.y = destinationRectangle.m_y;

        if (SDL_RenderCopy(g_sdlRenderer,
                           sdlTexture.Texture(),
                           &crop,
                           &rect))
        {
            throw Error{
                    SDL_GetError()
            };
        }
    }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Rectangle &destinationRectangle,
                                  const Rectangle *const sourceRectangle,
                                  const Color &color,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Rectangle &destinationRectangle,
                                  const Rectangle *const sourceRectangle,
                                  const Color &color,
                                  float rotation,
                                  const Vector2 &origin,
                                  DrawEffects drawEffects,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Vector2 &position,
                                  const Color &color,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Vector2 &position,
                                  const Rectangle *const sourceRectangle,
                                  const Color &color,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Vector2 &position,
                                  const Rectangle *const sourceRectangle,
                                  const Color &color,
                                  float rotation,
                                  const Vector2 &origin,
                                  float scale,
                                  DrawEffects drawEffects,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawTexture(const Texture &texture,
                                  const Vector2 &position,
                                  const Rectangle *const sourceRectangle,
                                  const Color &color,
                                  float rotation,
                                  const Vector2 &origin,
                                  const Vector2 &scale,
                                  DrawEffects drawEffects,
                                  BlendMode blendMode)
    { }

    void SdlGraphics::DrawString(const std::string &string,
                                 const Font &font,
                                 const Vector2 &position,
                                 const Color &color,
                                 BlendMode blendMode)
    { }

    void SdlGraphics::DrawString(const std::string &string,
                                 const Font &font,
                                 const Vector2 &position,
                                 const Color &color,
                                 float rotation,
                                 const Vector2 &origin,
                                 float scale,
                                 float spacing,
                                 DrawEffects drawEffects,
                                 BlendMode blendMode)
    { }

    void SdlGraphics::DrawString(const std::string &string,
                                 const Font &font,
                                 const Vector2 &position,
                                 const Color &color,
                                 float rotation,
                                 const Vector2 &origin,
                                 const Vector2 &scale,
                                 float spacing,
                                 DrawEffects drawEffects,
                                 BlendMode blendMode)
    { }

}
