#include <gem/Texture.hpp>
#include <gem/Point.hpp>

namespace Deadstorm
{
    inline void AnimSprite::SetPosition(int x, int y)
    {
        Sprite::SetPosition(x, y);

        m_controlRectangle.m_x = m_currentPosition.m_x - (m_frameWidth / 2);
        m_controlRectangle.m_y = m_currentPosition.m_y - m_frameHeight - 10;
    }

    inline Gem::Rectangle &AnimSprite::Rectangle()
    {
        return m_controlRectangle;
    }

    inline const Gem::Rectangle &AnimSprite::Rectangle() const
    {
        return m_controlRectangle;
    }

    inline void AnimSprite::SetDisplaySize(int w, int h)
    {
        m_controlRectangle.m_width = w;
        m_controlRectangle.m_height = h;
    }

    inline void AnimSprite::SetFrame(int x, int y)
    {
        SourceRectangle().m_x = x * m_frameWidth;
        SourceRectangle().m_y = y * m_frameHeight;
    }
}
