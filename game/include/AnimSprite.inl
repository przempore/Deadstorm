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

    inline void AnimSprite::SetPlace(int x, int y)
    {
        m_movingRect.m_x = x;
        m_movingRect.m_y = y;
    }

    inline void AnimSprite::SetDisplaySize(int w, int h)
    {
        m_movingRect.m_width = w;
        m_movingRect.m_height = h;
    }
}