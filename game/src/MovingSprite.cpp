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

    MovingSprite::MovingSprite(const std::string &path, int posX, int posY, int camX, int camY, bool cached)
            : MovingSprite(path, Gem::Point(posX, posY), Gem::Point(camX, camY), cached)
    {}

    MovingSprite::MovingSprite(const std::string &path, Gem::Point pos, bool cached)
            : MovingSprite(path, cached)
    {
        m_currentPosition = pos;
    }

    MovingSprite::MovingSprite(const std::string &path, Gem::Point pos, Gem::Point camPos, bool cached)
            : MovingSprite(path, pos, cached)
    {
        m_cameraPosition = camPos;
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
        uint32_t time = SDL_GetTicks() - m_startTime;
        float factor_x = LinearTween(time, 0, 1, m_duration);
        float factor_y = LinearTween(time, 0, 1, m_duration);

        int x = getPositionWithFactor(m_currentPosition.m_x, m_destination.m_x, factor_x);
        int y = getPositionWithFactor(m_currentPosition.m_y, m_destination.m_y, factor_y);
        SetPosition(x ,y);

        m_isMoving = isMovingEnd();
    }

    void MovingSprite::StartMovingTo(int x, int y)
    {
        m_isMoving = SetDestination(x, y);
        m_startPoint = m_currentPosition;
        m_startTime = SDL_GetTicks();
    	std::cerr << "camPos: " << m_cameraPosition.m_x << "," << m_cameraPosition.m_y << std::endl;
    }
}
