#ifndef DEADSTORM_SPRITE_HPP
#define DEADSTORM_SPRITE_HPP

#include <gem/TexturePart.hpp>
#include <gem/Point.hpp>

namespace Deadstorm
{
    class Sprite
    {
    public:
        Sprite() = delete;
        Sprite(const std::string &path, bool cached = false);
        virtual ~Sprite();

    public:
        inline Gem::TexturePtr Texture();
        inline Gem::ConstTexturePtr Texture() const;
        inline Gem::Rectangle& SourceRectangle();
        inline const Gem::Rectangle SourceRectangle() const;
        virtual inline void SetPosition(int x, int y);

    protected:
        Gem::TexturePartPtr m_texturePart;
        Gem::Point m_currentPosition;
    };

    typedef std::shared_ptr<Sprite> SpritePtr;
}

#include "Sprite.inl"

#endif //DEADSTORM_SPRITE_HPP
