#ifndef GEM_TEXTURE_PART_HPP
#define GEM_TEXTURE_PART_HPP

#include "gem/Asset.hpp"
#include "gem/Rectangle.hpp"

#include <memory>
#include <string>

namespace Gem
{
    class Texture;

    typedef std::shared_ptr<Texture> TexturePtr;
    typedef std::shared_ptr<const Texture> ConstTexturePtr;

    class TexturePart : public Asset
    {
    public:
        static AssetPtr Load(const std::string& path,
                             bool cache=false);

    public:
        inline TexturePtr Texture();
        inline ConstTexturePtr Texture() const;

        inline Rectangle& SourceRectangle();
        inline const Rectangle& SourceRectangle() const ;

    private:
        inline TexturePart(TexturePtr texture,
                           const Rectangle& sourceRectangle);

    private:
        TexturePtr m_texture;
        Rectangle m_sourceRectangle;
    };

    typedef std::shared_ptr<Gem::TexturePart> TexturePartPtr;
}

#include "gem/TexturePart.inl"

#endif
