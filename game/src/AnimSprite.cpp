#include <iostream>
#include <gem/Content.hpp>
#include <gem/Error.hpp>
#include <SDL_timer.h>
#include "AnimSprite.hpp"

namespace Deadstorm
{
    using namespace std;

    AnimSprite::AnimSprite(const std::string &path, int row, int col, bool cached)
            : m_row(row),
              m_col(col),
              m_animDeelay(0),
              m_currentFrame(0)
    {
        try
        {
            m_texturePart = g_content.Acquire<Gem::TexturePart>(path, cached);
        }
        catch (Gem::Error er)
        {
            std::cerr << er.What() << std::endl;
        }

        m_movingRect = {SourceRectangle().m_x,
                        SourceRectangle().m_y,
                        SourceRectangle().m_width,
                        SourceRectangle().m_height};

        m_rectangleWidth = SourceRectangle().m_width / m_col;
        m_rectangleHeight = SourceRectangle().m_height / m_row;

        SourceRectangle().Reset(0 * m_rectangleWidth,
                                0 * m_rectangleHeight,
                                SourceRectangle().m_width / m_col,
                                SourceRectangle().m_height / m_row);
        SetFrame(0, 0);
        SetPlace(0, 0);
    }

    AnimSprite::AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : AnimSprite(path, row, col, cached)
    {
        SetDisplaySize(dw, dh);
    }

    AnimSprite::~AnimSprite()
    { }

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
        Animate(0, 2, 0, 200);
    }
}
