#include "gem/Texture.hpp"

#include "gem/detail/SdlTexture.hpp"

using namespace std;

namespace Gem
{
    AssetPtr Texture::Load(const string& path, bool)
    {
        return SdlTexture::Load(path.c_str());
    }
}
