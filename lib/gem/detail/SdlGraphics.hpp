#ifndef GEM_SDL_GRAPHICS_HPP
#define GEM_SDL_GRAPHICS_HPP

#include "gem/Graphics.hpp"

namespace Gem
{
    class SdlGraphics : public Graphics
    {
    public:
	    virtual void Clear(const Color &color);
	    virtual void DrawTexture(const Texture &texture,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Rectangle &destinationRectangle,
	                             const Color &color,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Rectangle &destinationRectangle,
	                             const Rectangle *const sourceRectangle,
	                             const Color &color,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Rectangle &destinationRectangle,
	                             const Rectangle *const sourceRectangle,
	                             const Color &color,
	                             float rotation,
	                             const Vector2 &origin,
	                             DrawEffects drawEffects = DrawEffects::None,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Vector2 &position,
	                             const Color &color,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Vector2 &position,
	                             const Rectangle *const sourceRectangle,
	                             const Color &color,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Vector2 &position,
	                             const Rectangle *const sourceRectangle,
	                             const Color &color,
	                             float rotation,
	                             const Vector2 &origin,
	                             float scale,
	                             DrawEffects drawEffects = DrawEffects::None,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawTexture(const Texture &texture,
	                             const Vector2 &position,
	                             const Rectangle *const sourceRectangle,
	                             const Color &color,
	                             float rotation,
	                             const Vector2 &origin,
	                             const Vector2 &scale,
	                             DrawEffects drawEffects = DrawEffects::None,
	                             BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawString(const std::string &string,
	                            const Font &font,
	                            const Vector2 &position,
	                            const Color &color,
	                            BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawString(const std::string &string,
	                            const Font &font,
	                            const Vector2 &position,
	                            const Color &color,
	                            float rotation,
	                            const Vector2 &origin,
	                            float scale,
	                            float spacing = 0.f,
	                            DrawEffects drawEffects = DrawEffects::None,
	                            BlendMode blendMode = BlendMode::AlphaBlend);
	    virtual void DrawString(const std::string &string,
	                            const Font &font,
	                            const Vector2 &position,
	                            const Color &color,
	                            float rotation,
	                            const Vector2 &origin,
	                            const Vector2 &scale,
	                            float spacing = 0.f,
	                            DrawEffects drawEffects = DrawEffects::None,
	                            BlendMode blendMode = BlendMode::AlphaBlend);
    };
}

#endif // ifndef GEM_SDL_GRAPHICS_HPP
