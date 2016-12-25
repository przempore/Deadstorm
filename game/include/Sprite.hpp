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
        Sprite(const std::string &path, int dw, int dh, bool cached = false);
        virtual ~Sprite();

    public:
        virtual inline Gem::TexturePtr Texture();
        virtual inline Gem::ConstTexturePtr Texture() const;
        virtual inline Gem::Rectangle& SourceRectangle();
        virtual inline const Gem::Rectangle SourceRectangle() const;
        virtual inline Gem::Rectangle& Rectangle();
        virtual inline const Gem::Rectangle& Rectangle() const;
        virtual inline void SetPosition(int x, int y);
        virtual inline Gem::Point GetPosition();
        virtual inline void SetDisplaySize(int w, int h);
        virtual inline void SetCamPos(int x, int y);
        virtual inline Gem::Point GetCamPos();

    protected:
        virtual inline void SetPoint(Gem::Point *point, int x, int y);

    protected:
        Gem::Rectangle m_controlRectangle;
        Gem::TexturePartPtr m_texturePart;
        Gem::Point m_currentPosition;
        Gem::Point m_cameraPosition;
    };

    typedef std::shared_ptr<Sprite> SpritePtr;
}

#include "Sprite.inl"

#endif //DEADSTORM_SPRITE_HPP
