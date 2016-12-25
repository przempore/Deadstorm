#include "Defines.hpp"
#include "MovingSprite.hpp"
#include <tools/Math.hpp>

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
        if (positionIsEqual(x, y))
        {
            return false;
        }

        SetPoint(&m_destination, x, y);

        return true;
    }

    inline bool MovingSprite::positionIsEqual(const int x, const int y) const
    {
        return m_currentPosition.m_x == x
               && m_currentPosition.m_y == y;
    }

    inline float MovingSprite::LinearTween(float currentTime, float startValue,
                                         float changeInValue, float duration)
    {
        return changeInValue * currentTime / duration + startValue;
    }

    inline int MovingSprite::getPositionWithFactor(int currentPos, int destination, float factor_y) const
    {
        return static_cast<int>(currentPos + (destination - currentPos) * factor_y);
    }

    inline bool MovingSprite::isMovingEnd() const
    {
        return !Tools::IsEqual<int>(m_currentPosition.m_x, m_destination.m_x, m_epsilon)
               || !Tools::IsEqual<int>(m_currentPosition.m_y, m_destination.m_y, m_epsilon);
    }
}
