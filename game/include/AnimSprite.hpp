#ifndef DEADSTORM_ANIMSPRITE_HPP
#define DEADSTORM_ANIMSPRITE_HPP

#include "Sprite.hpp"

namespace Deadstorm
{
    class AnimSprite : public virtual Sprite
    {
    public:
        AnimSprite(const std::string &path, int row, int col, bool cached = false);
        AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached = false);

        virtual ~AnimSprite();

    public:
        virtual inline void SetFrame(int x, int y);
        virtual inline void SetPosition(int x, int y) override;

    public:
        void Animate(float angle);

    private:
        void Animate(int beginFrame, int endFrame, int row, float deelay);

    private:
        int m_row = 0;
        int m_col = 0;
        float m_animDeelay = 0;
        int m_currentFrame = 0;
    };

    typedef std::shared_ptr<AnimSprite> AnimSpritePtr;
}

#include "AnimSprite.inl"

#endif //DEADSTORM_ANIMSPRITE_HPP
