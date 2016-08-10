#include "Defines.hpp"

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

    inline const Gem::Rectangle &Sprite::Rectangle() const
    {
        return m_controlRectangle;
    }

    inline void Sprite::SetPosition(int x, int y)
    {
        SetPoint(&m_currentPosition, x, y);
//        m_currentPosition.m_x = x;
//        m_currentPosition.m_y = y;
    }

    inline void Sprite::SetDisplaySize(int w, int h)
    {
        m_controlRectangle.m_width = w;
        m_controlRectangle.m_height = h;
    }

    inline void Sprite::SetPoint(Gem::Point *point, int x, int y)
    {
        const int minX{
                17
        };
        const int maxX{
                g_screenWidth - minX
        };
        const int minY{
                44
        };
        const int maxY{
                g_screenHeight
        };

        if (x < minX)
        {
            point->m_x = minX;
        }
        else if (x > maxX)
        {
            point->m_x = maxX;
        }
        else
        {
            point->m_x = x;
        }

        if (y < minY)
        {
            point->m_y = minY;
        }
        else if (y > maxY)
        {
            point->m_y = maxY;
        }
        else
        {
            point->m_y = y;
        }
    }
}
