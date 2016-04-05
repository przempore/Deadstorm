#include <iostream>
#include <gem/Content.hpp>
#include <gem/Error.hpp>
#include "AnimSprite.hpp"

namespace Deadstorm
{
    AnimSprite::AnimSprite(const std::string &path, int row, int col, int dw, int dh, bool cached)
            : m_row(row),
              m_col(col)
    {
        try
        {
            m_texturePart = g_content.Acquire<Gem::TexturePart>(path, cached);
        }
        catch (Gem::Error er)
        {
            std::cerr << er.What() << std::endl;
        }

        m_movingRect = {m_texturePart->SourceRectangle().m_x,
                        m_texturePart->SourceRectangle().m_y,
                        m_texturePart->SourceRectangle().m_width,
                        m_texturePart->SourceRectangle().m_height};
        SetFrame(0, 0);
        SetPlace(25, 38);
        SetDisplaySize(dw, dh);
    }

    AnimSprite::~AnimSprite()
    { }

    void AnimSprite::SetFrame(int x, int y)
    {
        m_texturePart->SourceRectangle().Reset(x * (m_texturePart->SourceRectangle().m_width),
                                               y * (m_texturePart->SourceRectangle().m_height),
                                               m_texturePart->SourceRectangle().m_width / m_col,
                                               m_texturePart->SourceRectangle().m_height / m_row);
    }


}
