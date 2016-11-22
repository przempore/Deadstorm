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
        inline float LinearTween(float currentTime, float startValue,
                                 float changeInValue, float duration);

    public:
        float GetMovingAngle();
        virtual void Move();
        void StartMovingTo(int x, int y);

    private:
        inline bool SetDestination(int x, int y);

    private:
        bool m_isMoving = false;
        Gem::Point m_destination;
        Gem::Point m_startPoint;
        uint32_t m_startTime;
        uint32_t m_endTime;
        uint32_t m_duration = 2500;
    };

    typedef std::shared_ptr<MovingSprite> MovingSpritePtr;
}

#include "MovingSprite.inl"

#endif //DEADSTORM_MOVINGSPRITE_HPP
