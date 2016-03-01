#ifndef GEM_GRAPHICS_HPP
#define GEM_GRAPHICS_HPP

#include "gem/BlendMode.hpp"
#include "gem/DrawEffects.hpp"

#include <boost/noncopyable.hpp>

#include <memory>
#include <string>

namespace Gem
{
    class Color;
    class Font;
    class Rectangle;
    class Texture;
    class Vector2;

    class Graphics : private boost::noncopyable
    {
    public:
        virtual void Clear(const Color& color) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Rectangle& destinationRectangle,
                                 const Color& color,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Rectangle& destinationRectangle,
                                 const Rectangle* const sourceRectangle,
                                 const Color& color,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Rectangle& destinationRectangle,
                                 const Rectangle* const sourceRectangle,
                                 const Color& color,
                                 float rotation,
                                 const Vector2& origin,
                                 DrawEffects drawEffects=DrawEffects::None,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Vector2& position,
                                 const Color& color,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Vector2& position,
                                 const Rectangle* const sourceRectangle,
                                 const Color& color,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Vector2& position,
                                 const Rectangle* const sourceRectangle,
                                 const Color& color,
                                 float rotation,
                                 const Vector2& origin,
                                 float scale,
                                 DrawEffects drawEffects=DrawEffects::None,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawTexture(const Texture& texture,
                                 const Vector2& position,
                                 const Rectangle* const sourceRectangle,
                                 const Color& color,
                                 float rotation,
                                 const Vector2& origin,
                                 const Vector2& scale,
                                 DrawEffects drawEffects=DrawEffects::None,
                                 BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawString(const std::string& string,
                                const Font& font,
                                const Vector2& position,
                                const Color& color,
                                BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawString(const std::string& string,
                                const Font& font,
                                const Vector2& position,
                                const Color& color,
                                float rotation,
                                const Vector2& origin,
                                float scale,
                                float spacing=0.f,
                                DrawEffects drawEffects=DrawEffects::None,
                                BlendMode blendMode=BlendMode::AlphaBlend) = 0;
        virtual void DrawString(const std::string& string,
                                const Font& font,
                                const Vector2& position,
                                const Color& color,
                                float rotation,
                                const Vector2& origin,
                                const Vector2& scale,
                                float spacing=0.f,
                                DrawEffects drawEffects=DrawEffects::None,
                                BlendMode blendMode=BlendMode::AlphaBlend) = 0;
    };
}

#endif
