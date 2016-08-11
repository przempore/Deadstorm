#include <iostream>
#include "Sprite.hpp"
#include <gem/Content.hpp>
#include <gem/Error.hpp>
#include <gem/Texture.hpp>

namespace Deadstorm
{
    Sprite::Sprite(const std::string &path, bool cached)
    {
        Gem::TexturePtr tex;
        try
        {
            m_texturePart = g_content.Acquire<Gem::TexturePart>(path, cached);
            tex = m_texturePart->Texture();
        }
        catch (Gem::Error er)
        {
            std::cerr << "file: " << __FILE__ << ", line: " << __LINE__ << std::endl;
            std::cerr << er.What() << std::endl;
        }

        int w = tex->Width();
        std::cerr << "w: " << w << std::endl;

        SetPosition(0, 0);

        m_controlRectangle = {
                SourceRectangle().m_x,
                SourceRectangle().m_y,
                SourceRectangle().m_width,
                SourceRectangle().m_height
        };
        
        SetDisplaySize(SourceRectangle().m_width, SourceRectangle().m_height);
    }

    Sprite::Sprite(const std::string &path, int dw, int dh, bool cached)
            : Sprite(path, cached)
    {
        SetDisplaySize(dw, dh);
    }

    Sprite::~Sprite()
    {}
}