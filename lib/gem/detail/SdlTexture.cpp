#include "gem/detail/SdlTexture.hpp"

#include "gem/Assert.hpp"
#include "gem/Error.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include <string>

using namespace std;

namespace Gem
{
    extern SDL_Renderer *g_sdlRenderer;

    SdlTexture::SdlTexture(SDL_Texture *texture,
                           int width,
                           int height) : m_texture(texture),
                                         m_width(width),
                                         m_height(height)
    {
        GEM_ASSERT(texture);
        GEM_ASSERT(width > 0);
        GEM_ASSERT(height > 0);
    }

    SdlTexture::~SdlTexture()
    {
        SDL_DestroyTexture(m_texture);
    }

    SdlTexturePtr SdlTexture::Load(const char *path)
    {
        GEM_ASSERT(path);

        auto SDL_SurfaceDeleter = [](SDL_Surface *surface) {
            SDL_FreeSurface(surface);
        };

        // todo: why lambda doesn't work here
//        auto SDL_TextureDeleter = [](SDL_Texture *texture) {
//            SDL_DestroyTexture(texture);
//        };

        struct SDL_TextureDeleter
        {
            void operator()(SDL_Texture *texture) const
            {
                SDL_DestroyTexture(texture);
            }
        };

        typedef unique_ptr<SDL_Surface, decltype(SDL_SurfaceDeleter)> SDL_SurfacePtr;
        typedef unique_ptr<SDL_Texture, SDL_TextureDeleter> SDL_TexturePtr;

        SDL_SurfacePtr surface{
                IMG_Load(path),
                SDL_SurfaceDeleter
        };

        if (!surface)
        {
            throw Error{
                    "image loading failed"
            };
        }

        SDL_TexturePtr texture{
                SDL_CreateTextureFromSurface(g_sdlRenderer,
                                             surface.get())
        };

        if (!texture)
        {
            throw Error("texture creation failed");
        }

        return SdlTexturePtr{
                new SdlTexture(texture.release(),
                               surface->w,
                               surface->h)
        };
    }

    int SdlTexture::Width() const
    {
        return m_width;
    }

    int SdlTexture::Height() const
    {
        return m_height;
    }

}
