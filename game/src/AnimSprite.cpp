#include <iostream>
#include <SDL_timer.h>
#include "AnimSprite.hpp"

namespace Deadstorm
{
    AnimSprite::AnimSprite(const std::string &path, int row, int col, bool cached)
            : AnimSprite(path, row, col, SourceRectangle().m_width / m_col,
                    SourceRectangle().m_height / m_row, cached)
    {}

    AnimSprite::AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : Sprite(path, cached),
              m_row(row),
              m_col(col),
              m_animDeelay(0),
              m_currentFrame(0)
    {
        SourceRectangle().Reset(0, 0, SourceRectangle().m_width / m_col, SourceRectangle().m_height / m_row);
        SetDisplaySize(dw, dw);
        SetPosition(dw / 2, dw + 10);
        SetFrame(0, 0);
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
