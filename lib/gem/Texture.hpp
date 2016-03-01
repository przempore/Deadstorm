#ifndef GEM_TEXTURE_HPP
#define GEM_TEXTURE_HPP

#include "gem/Asset.hpp"

#include <memory>
#include <string>

namespace Gem
{
    class Texture : public Asset
    {
    public:
        static AssetPtr Load(const std::string& path,
                             bool cache=false);

    public:
        virtual int Width() const = 0;
        virtual int Height() const = 0;
    };

    typedef std::shared_ptr<Texture> TexturePtr;
    typedef std::shared_ptr<const Texture> ConstTexturePtr;
}

#endif
