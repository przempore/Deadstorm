#include <tools/Math.hpp>
#include <tgmath.h>
#include "MovingSprite.hpp"

namespace Deadstorm
{
    MovingSprite::MovingSprite(const std::string &path, bool cached) : Sprite(path, cached)
    {}

    MovingSprite::MovingSprite(const std::string &path, int posX, int posY, bool cached)
            : MovingSprite(path, Gem::Point(posX, posY), cached)
    {}

    MovingSprite::MovingSprite(const std::string &path, Gem::Point pos, bool cached)
            : MovingSprite(path, cached)
    {
        m_currentPosition = pos;
    }

    MovingSprite::~MovingSprite()
    {}

    float MovingSprite::GetMovingAngle()
    {
        float angle = std::atan2(m_destination.m_y - m_currentPosition.m_y, m_destination.m_x - m_currentPosition.m_x);
        return ((angle * (180 / 3.14f)) + 180);

    }

    void MovingSprite::Move()
    {
        m_distance = Tools::GetDistance(m_currentPosition.m_x, m_currentPosition.m_y, m_destination.m_x,
                                        m_destination.m_y);

        int x = static_cast<int>(m_currentPosition.m_x -
                                 (((m_currentPosition.m_x - m_destination.m_x) / m_distance) * m_movingSpeed));
        int y = static_cast<int>(m_currentPosition.m_y -
                                 (((m_currentPosition.m_y - m_destination.m_y) / m_distance) * m_movingSpeed));

        SetPosition(x, y);

        m_isMoving = !Tools::IsEqual<int>(m_currentPosition.m_x, m_destination.m_x, m_movingSpeed)
                     || !Tools::IsEqual<int>(m_currentPosition.m_y, m_destination.m_y, m_movingSpeed);
    }

    void MovingSprite::MoveTo(int x, int y)
    {
        m_isMoving = SetDestination(x, y);
    }
}