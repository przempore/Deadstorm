#include "Defines.hpp"

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

    bool MovingSprite::SetDestination(int x, int y)
    {
        if (m_currentPosition.m_x == x
            && m_currentPosition.m_y == y)
        {
            return false;
        }

        const int minX{
                17
        };
        const int maxX{
                g_screenWidth - minX
        };
        const int minY{
                44
        };
        const int maxY{
                g_screenHeight
        };

        if (x < minX)
        {
            m_destination.m_x = minX;
        }
        else if (x > maxX)
        {
            m_destination.m_x = maxX;
        }
        else
        {
            m_destination.m_x = x;
        }

        if (y < minY)
        {
            m_destination.m_y = minY;
        }
        else if (y > maxY)
        {
            m_destination.m_y = maxY;
        }
        else
        {
            m_destination.m_y = y;
        }

        return true;
    }
}