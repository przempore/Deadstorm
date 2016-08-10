#ifndef DEADSTORM_MOVINGSPRITE_HPP
#define DEADSTORM_MOVINGSPRITE_HPP

#include "Sprite.hpp"

namespace Deadstorm
{
    class MovingSprite : public virtual Sprite
    {
    public:
        MovingSprite(const std::string &path, bool cached = false);
        MovingSprite(const std::string &path, int posX, int posY, bool cached = false);
        MovingSprite(const std::string &path, Gem::Point pos, bool cached = false);

        MovingSprite();

        virtual ~MovingSprite();

    public:
        inline bool IsMoving() const;
        inline void SetMoving(const bool isMoving);

    public:
        float GetMovingAngle();
        virtual void Move();
        void MoveTo(int x, int y);

    private:
        inline bool SetDestination(int x, int y);

    private:
        bool m_isMoving = false;
        Gem::Point m_destination;
        static const int m_movingSpeed = 3;
        float m_distance = 0.f;
    };

    typedef std::shared_ptr<MovingSprite> MovingSpritePtr;
}

#include "MovingSprite.inl"

#endif //DEADSTORM_MOVINGSPRITE_HPP
