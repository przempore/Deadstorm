#include <iostream>
#include <SDL_timer.h>
#include <tools/Math.hpp>
#include "AnimSprite.hpp"

namespace Deadstorm
{
    AnimSprite::AnimSprite(const std::string &path, int row, int col, bool cached)
            : Sprite(path, cached),
              m_row(row),
              m_col(col),
              m_animDeelay(0),
              m_currentFrame(0)
    {
        m_controlRectangle = {
                SourceRectangle().m_x,
                SourceRectangle().m_y,
                SourceRectangle().m_width,
                SourceRectangle().m_height
        };

        m_controlRectangleWidth = SourceRectangle().m_width / m_col;
        m_controlRectangleHeight = SourceRectangle().m_height / m_row;

        SourceRectangle().Reset(0, 0, m_controlRectangleWidth, m_controlRectangleHeight);

        SetPosition(m_controlRectangleWidth / 2, m_controlRectangleHeight + 10);
        SetFrame(0, 0);
    }

    AnimSprite::AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : AnimSprite(path, row, col, cached)
    {
        SetDisplaySize(dw, dh);
    }

    AnimSprite::~AnimSprite()
    {}

    void AnimSprite::Animate()
    {
        if (!m_isMoving)
        {
            return;
        }

        float angle = atan2(m_destination.m_y - m_currentPosition.m_y, m_destination.m_x - m_currentPosition.m_x);
        angle = ((angle * (180 / 3.14f)) + 180);
        if (angle > 45 && angle <= 135)
        {
            //down
            Animate(0, 2, 3, 200);
        }
        else if (angle > 135 && angle <= 225)
        {
            //left
            Animate(0, 2, 2, 200);
        }
        else if (angle > 225 && angle <= 315)
        {
            //up
            Animate(0, 2, 0, 200);
        }
        else if ((angle <= 365 && angle > 315) || (angle >= 0 && angle <= 45))
        {
            //right
            Animate(0, 2, 1, 200);
        }
    }

    void AnimSprite::Animate(int beginFrame, int endFrame, int row, float deelay)
    {
        if ((m_animDeelay + deelay) > SDL_GetTicks())
        {
            return;
        }

        if (endFrame <= m_currentFrame)
        {
            m_currentFrame = beginFrame;
        }
        else
        {
            ++m_currentFrame;
        }

        SetFrame(m_currentFrame, row);

        m_animDeelay = SDL_GetTicks();
    }

    void AnimSprite::Move()
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

    void AnimSprite::MoveTo(int x, int y)
    {
        m_isMoving = SetDestination(x, y);
    }
}
