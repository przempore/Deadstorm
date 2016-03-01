#ifndef GEM_SDL_TEXTURE_HPP
#define GEM_SDL_TEXTURE_HPP

#include "gem/Texture.hpp"

struct SDL_Texture;

namespace Gem
{
	class SdlTexture;

	typedef std::shared_ptr< SdlTexture > SdlTexturePtr;

	class SdlTexture : public Texture
	{
	public:
		SdlTexture( SDL_Texture* texture,
					int width,
					int height );
		virtual ~SdlTexture();

	public:
		static SdlTexturePtr Load( const char* path );

	public:
		virtual int Width() const;
		virtual int Height() const;

	public:
		inline SDL_Texture* Texture() const;

	private:
		SDL_Texture* m_texture;
		int          m_width;
		int          m_height;
	};
}

#include "gem/detail/SdlTexture.inl"

#endif // ifndef GEM_SDL_TEXTURE_HPP
