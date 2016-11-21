#include <tools/Math.hpp>
#include <iostream>
#include <SDL_timer.h>
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
        /*m_distance = Tools::GetDistance(m_currentPosition.m_x, m_currentPosition.m_y, m_destination.m_x,
                                        m_destination.m_y);

        int x = static_cast<int>(m_currentPosition.m_x -
                                 (((m_currentPosition.m_x - m_destination.m_x) / m_distance) * m_movingSpeed));
        int x = static_cast<int>(m_currentPosition.m_y -
                                 (((m_currentPosition.m_y - m_destination.m_y) / m_distance) * m_movingSpeed));

        SetPosition(x, y);

        m_isMoving = !Tools::IsEqual<int>(m_currentPosition.m_x, m_destination.m_x, m_movingSpeed)
                     || !Tools::IsEqual<int>(m_currentPosition.m_y, m_destination.m_y, m_movingSpeed);*/
        std::cerr << "m_startPoint.m_x: " << m_startPoint.m_x << std::endl;
        std::cerr << "m_startPoint.m_y: " << m_startPoint.m_y << std::endl;
        uint32_t time = SDL_GetTicks() - m_startTime;
        uint32_t x = LinearTween(time, static_cast<uint32_t>(m_startPoint.m_x), 5, 50);
        uint32_t y = LinearTween(time, static_cast<uint32_t>(m_startPoint.m_y), 5, 50);
        std::cerr << "time: " << time << std::endl;
        std::cerr << "m_currentPosition.m_x: " << GetPosition().m_x << std::endl;
        std::cerr << "m_currentPosition.m_y: " << GetPosition().m_y << std::endl;
        std::cerr << "x: " << x << std::endl;
        std::cerr << "y: " << y << std::endl;
        std::cerr << "---------------------------------------------------------------" << std::endl;

        SetPosition(x, y);

        if (SDL_GetTicks() >= m_endTime)
        {
            m_isMoving = false;
        }
    }

    void MovingSprite::MoveTo(int x, int y)
    {
        m_isMoving = SetDestination(x, y);
        m_startPoint = m_currentPosition;
        m_startTime = SDL_GetTicks();
        m_endTime = m_startTime + 500;
    }
}