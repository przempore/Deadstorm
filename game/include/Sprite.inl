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

    inline void Sprite::SetPosition(int x, int y)
    {
        SetPoint(&m_currentPosition, x, y);
//        m_currentPosition.m_x = x;
//        m_currentPosition.m_y = y;
    }
    inline Gem::Point Sprite::GetPosition()
    {
        return m_currentPosition;
    }

    inline void Sprite::SetCamPos(int x, int y)
    {
        m_cameraPosition.m_x = x;
        m_cameraPosition.m_y = y;
    }
    inline Gem::Point Sprite::GetCamPos()
    {
        return m_cameraPosition;
    }
    
    inline Gem::Rectangle &Sprite::Rectangle()
    {
        return m_controlRectangle;
    }

    inline const Gem::Rectangle &Sprite::Rectangle() const
    {
        return m_controlRectangle;
    }

    inline void Sprite::SetDisplaySize(int w, int h)
    {
        m_controlRectangle.m_width = w;
        m_controlRectangle.m_height = h;
    }

    inline void Sprite::SetPoint(Gem::Point *point, int x, int y)
    {
        const int minX{
                m_controlRectangle.m_width / 2
        };
        const int minY{
                m_controlRectangle.m_height + 10
        };

        if (x < minX)
        {
            point->m_x = minX;
        }
        else if (x > (g_screenWidth - minX))
        {
            point->m_x = g_screenWidth - minX;
        }
        else
        {
            point->m_x = x;
        }

        if (y < minY)
        {
            point->m_y = minY;
        }
        else if (y > g_screenHeight)
        {
            point->m_y = g_screenHeight;
        }
        else
        {
            point->m_y = y;
        }
    }
}
