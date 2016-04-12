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
        AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached = false);

        virtual ~AnimSprite();

    public:
        inline void SetFrame(int x, int y);
        inline Gem::TexturePtr Texture();
        inline Gem::ConstTexturePtr Texture() const;
        inline Gem::Rectangle& SourceRectangle();
        inline const Gem::Rectangle SourceRectangle() const;
        inline Gem::Rectangle& Rectangle();
        inline const Gem::Rectangle& Rectangle() const;
        inline void SetPlace(int x, int y);
        inline void SetDisplaySize(int w, int h);

    public:
        void Animate(int beginFrame, int endFrame, int row, float deelay);

    private:
        Gem::TexturePartPtr m_texturePart;
        Gem::Rectangle m_movingRect;
        int m_rectangleWidth;
        int m_rectangleHeight;
        int m_row = 0;
        int m_col = 0;
        float m_animDeelay = 0;
        int m_currentFrame = 0;
    };

    typedef std::shared_ptr<AnimSprite> AnimSpritePtr;
}

#include "AnimSprite.inl"

#endif //DEADSTORM_SPRITE_HPP
