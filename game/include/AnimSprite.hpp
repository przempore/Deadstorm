#ifndef DEADSTORM_ANIMSPRITE_HPP
#define DEADSTORM_ANIMSPRITE_HPP

#include <string>
#include "Sprite.hpp"

namespace Deadstorm
{
    class AnimSprite : public Sprite
    {
    public:
        AnimSprite(const std::string &path, int row, int col, bool cached = false);
        AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached = false);

        virtual ~AnimSprite();

    public:
        inline void SetFrame(int x, int y);
        inline bool IsMoving() const;
        inline void SetPosition(int x, int y) override;
        inline Gem::Rectangle& Rectangle();
        inline const Gem::Rectangle& Rectangle() const;
        inline void SetDisplaySize(int w, int h);

    public:
        void Move();
        void Animate();
        void MoveTo(int x, int y);

    private:
        void Animate(int beginFrame, int endFrame, int row, float deelay);
        inline void SetDestination(int x, int y);

    private:
        Gem::Rectangle m_controlRectangle;
        int m_controlRectangleWidth;
        int m_controlRectangleHeight;
        int m_row = 0;
        int m_col = 0;
        float m_animDeelay = 0;
        int m_currentFrame = 0;

    private:
        bool m_isMoving = false;
        Gem::Point m_destination;
        static const int m_movingSpeed = 3;
        float m_distance = 0.f;
    };

    typedef std::shared_ptr<AnimSprite> AnimSpritePtr;
}

#include "AnimSprite.inl"

#endif //DEADSTORM_ANIMSPRITE_HPP
