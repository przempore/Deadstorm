#include "AnimSprite.hpp"

namespace Deadstorm
{
    inline Gem::TexturePtr AnimSprite::Texture()
    {
        return m_texturePart->Texture();
    }

    inline Gem::ConstTexturePtr AnimSprite::Texture() const
    {
        return m_texturePart->Texture();
    }

    inline Gem::Rectangle &AnimSprite::Rectangle()
    {
        return m_movingRect;
    }

    inline const Gem::Rectangle &AnimSprite::Rectangle() const
    {
        return m_movingRect;
    }

    inline Gem::Rectangle &AnimSprite::SourceRectangle()
    {
        return m_texturePart->SourceRectangle();
    }

    inline const Gem::Rectangle AnimSprite::SourceRectangle() const
    {
        return m_texturePart->SourceRectangle();
    }

    inline void AnimSprite::SetPosition(int x, int y)
    {
        m_currentPosition.m_x = x;
        m_currentPosition.m_y = y;
        m_movingRect.m_x = m_currentPosition.m_x - (m_rectangleWidth / 2);
        m_movingRect.m_y = m_currentPosition.m_y - m_rectangleHeight - 10;
    }

    inline void AnimSprite::SetDisplaySize(int w, int h)
    {
        m_movingRect.m_width = w;
        m_movingRect.m_height = h;
    }

    inline void AnimSprite::SetFrame(int x, int y)
    {
        SourceRectangle().m_x = x * m_rectangleWidth;
        SourceRectangle().m_y = y * m_rectangleHeight;
    }

    inline bool AnimSprite::IsMoving() const
    {
        return m_isMoving;
    }

    inline void AnimSprite::SetDestination(int x, int y)
    {
        m_destination.m_x = x;
        m_destination.m_y = y;
    }
}
