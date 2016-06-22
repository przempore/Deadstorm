namespace Deadstorm
{
    inline Gem::TexturePtr Sprite::Texture()
    {
        return m_texturePart->Texture();
    }

    inline Gem::ConstTexturePtr Sprite::Texture() const
    {
        return m_texturePart->Texture();
    }

    inline Gem::Rectangle &Sprite::SourceRectangle()
    {
        return m_texturePart->SourceRectangle();
    }

    inline const Gem::Rectangle Sprite::SourceRectangle() const
    {
        return m_texturePart->SourceRectangle();
    }

    inline void Sprite::SetPosition(int x, int y)
    {
        m_currentPosition.m_x = x;
        m_currentPosition.m_y = y;

        m_texturePart->SourceRectangle().m_x = x;
        m_texturePart->SourceRectangle().m_y = y;
    }
}
