#include <iostream>
#include <SDL_timer.h>
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

        m_frameWidth = SourceRectangle().m_width / m_col;
        m_frameHeight = SourceRectangle().m_height / m_row;

        SourceRectangle().Reset(0, 0, m_frameWidth, m_frameHeight);

        SetDisplaySize(m_frameWidth, m_frameHeight);

        SetPosition(m_frameWidth / 2, m_frameHeight + 10);
        SetFrame(0, 0);
    }

    AnimSprite::AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : AnimSprite(path, row, col, cached)
    {
        SetDisplaySize(dw, dh);
    }

    AnimSprite::~AnimSprite()
    {}

    void AnimSprite::Animate(float angle)
    {
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
}
