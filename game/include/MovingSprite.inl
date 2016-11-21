#include "Defines.hpp"
#include "MovingSprite.hpp"

namespace Deadstorm
{

    inline bool MovingSprite::IsMoving() const
    {
        return m_isMoving;
    }

    inline void MovingSprite::SetMoving(const bool isMoving)
    {
        m_isMoving = isMoving;
    }

    inline bool MovingSprite::SetDestination(int x, int y)
    {
        if (m_currentPosition.m_x == x
            && m_currentPosition.m_y == y)
        {
            return false;
        }

        SetPoint(&m_destination, x, y);

        return true;
    }

    inline uint32_t MovingSprite::LinearTween(uint32_t currentTime, uint32_t startValue,
                                              uint32_t changeInValue, uint32_t duration)
    {
        return changeInValue * currentTime / duration + startValue;
    }
}