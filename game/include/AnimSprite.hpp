#ifndef DEADSTORM_SPRITE_HPP
#define DEADSTORM_SPRITE_HPP

#include <string>
#include <gem/TexturePart.hpp>

namespace Deadstorm
{
    class AnimSprite
    {
    public:
        AnimSprite(const std::string &path, int row, int col, bool cached = false);

        virtual ~AnimSprite();

    public:
        void SetFrame(int x, int y);

    public:
        inline Gem::TexturePtr Texture();
        inline Gem::ConstTexturePtr Texture() const;
        inline Gem::Rectangle& SourceRectangle();
        inline const Gem::Rectangle SourceRectangle() const;
        inline Gem::Rectangle& Rectangle();
        inline const Gem::Rectangle& Rectangle() const;

    public:
        inline void SetPlace(int x, int y);

    private:
        Gem::TexturePartPtr m_texturePart;
        Gem::Rectangle m_movingRect;
        int m_row;
        int m_col;
    };

    typedef std::shared_ptr<AnimSprite> AnimSpritePtr;
}

#include "AnimSprite.inl"

#endif //DEADSTORM_SPRITE_HPP
