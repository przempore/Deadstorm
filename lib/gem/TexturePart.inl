namespace Gem
{
    inline TexturePtr TexturePart::Texture()
    {
        return m_texture;
    }

    inline ConstTexturePtr TexturePart::Texture() const
    {
        return m_texture;
    }

    inline Rectangle& TexturePart::SourceRectangle()
    {
        return m_sourceRectangle;
    }

    inline const Rectangle& TexturePart::SourceRectangle() const
    {
        return m_sourceRectangle;
    }

    inline TexturePart::TexturePart(TexturePtr texture,
                                    const Rectangle& sourceRectangle)
        : m_texture(texture)
        , m_sourceRectangle(sourceRectangle)
    {
    }
}
