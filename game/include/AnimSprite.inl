#include <gem/Texture.hpp>
#include <gem/Point.hpp>

namespace Deadstorm
{
    inline void AnimSprite::SetPosition(int x, int y)
    {
        Sprite::SetPosition(x, y);

        m_controlRectangle.m_x = m_currentPosition.m_x - (SourceRectangle().m_width / 2);
        m_controlRectangle.m_y = m_currentPosition.m_y - SourceRectangle().m_height - 10;
    }

    inline void AnimSprite::SetFrame(int x, int y)
    {
        SourceRectangle().m_x = x * SourceRectangle().m_width;
        SourceRectangle().m_y = y * SourceRectangle().m_height;
    }
}
