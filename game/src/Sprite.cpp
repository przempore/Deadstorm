#include <iostream>
#include "Sprite.hpp"
#include <gem/Content.hpp>
#include <gem/Error.hpp>

namespace Deadstorm
{
    Sprite::Sprite(const std::string &path, bool cached)
    {
        try
        {
            m_texturePart = g_content.Acquire<Gem::TexturePart>(path, cached);
        }
        catch (Gem::Error er)
        {
            std::cerr << "file: " << __FILE__ << ", line: " << __LINE__ << std::endl;
            std::cerr << er.What() << std::endl;
        }

        SetPosition(0, 0);
    }

    Sprite::~Sprite()
    {}
}