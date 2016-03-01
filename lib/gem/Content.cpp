#include "gem/Content.hpp"

#include "gem/Error.hpp"
#include "gem/Texture.hpp"
#include "gem/TexturePart.hpp"

using namespace boost;
using namespace std;

namespace Gem
{
Content::Content()
{
	Register( "png", Texture::Load );
	Register( "gtp", TexturePart::Load );
}

AssetPtr Content::Acquire( const std::string& path,
						   bool cache )
{
	auto found = m_assets.find( path );

	if( found != m_assets.end() )
	{
		if( found->second.second )
		{
			return any_cast< AssetPtr >( found->second.first );
		}
		else
		{
			AssetWPtr asset = any_cast< AssetWPtr >( found->second.first );

			if( !asset.expired() )
			{
				return asset.lock();
			}
			else
			{
				return Load( path, cache );
			}
		}
	}
	else
	{
		return Load( path, cache );
	}
}

bool Content::Cached( const std::string& path ) const
{
	auto found = m_assets.find( path );

	return found != m_assets.end() ? found->second.second : false;
}

void Content::Register( const std::string& extension,
						Content::Loader loader )
{
	m_loaders[ extension ] = loader;
}

bool Content::Registered( const std::string& extension )
{
	return m_loaders.find( extension ) != m_loaders.end();
}

bool Content::Release( const std::string& path )
{
	auto found = m_assets.find( path );

	if( found != m_assets.end() )
	{
		m_assets.erase( found );

		return true;
	}

	return false;
}

Content::Loader Content::Unregister( const std::string& extension )
{
	auto found = m_loaders.find( extension );

	if( found != m_loaders.end() )
	{
		Loader loader = found->second;

		m_loaders.erase( found );

		return loader;
	}

	return nullptr;
}

std::string Content::Extension( const std::string& path ) const
{
	string::size_type found = path.find_last_of( '.' );

	if( found == string::npos )
	{
		throw Error( "unsupported asset path format detected" );
	}

	return path.substr( found + 1 );
}

AssetPtr Content::Load( const std::string& path,
						bool cache )
{
	GEM_ASSERT( m_assets.find( path ) == m_assets.end() );

	std::string extension = Extension( path );

	auto found = m_loaders.find( extension );

	if( found != m_loaders.end() )
	{
		Loader loader = found->second;

		AssetPtr asset = loader( path, cache );

		if( cache )
		{
			m_assets[ path ] = make_pair( any( asset ), cache );
		}
		else
		{
			m_assets[ path ] = make_pair( any( AssetWPtr( asset ) ), cache );
		}

		asset->Initialize();

		return asset;
	}
	else
	{
		throw Error( "unsupported asset extension detected" );
	}

	return nullptr;
}

}
