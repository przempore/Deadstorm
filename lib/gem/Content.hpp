#ifndef GEM_CONTENT_HPP
#define GEM_CONTENT_HPP

#include "gem/Asset.hpp"
#include "gem/Singleton.hpp"

#include <boost/any.hpp>

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

namespace Gem
{
	class Content : public Singleton< Content >
	{
	public:
		typedef std::pair< boost::any, bool >                         AssetEntry;
		typedef std::function< AssetPtr( const std::string&, bool ) > Loader;
		typedef std::unordered_map< std::string, AssetEntry >         AssetEntryMap;
		typedef std::unordered_map< std::string, Loader >             LoaderMap;

	public:
		Content();

	public:
		AssetPtr Acquire( const std::string& path,
						  bool cache = false );
		template< class T_ >
		inline std::shared_ptr< T_ > Acquire( const std::string& path,
											  bool cache = false );
		bool Cached( const std::string& path ) const;
		void Register( const std::string& extension,
					   Loader loader );
		bool Registered( const std::string& extension );
		bool Release( const std::string& path );
		Loader Unregister( const std::string& extension );

	private:
		std::string Extension( const std::string& path ) const;
		AssetPtr Load( const std::string& path,
					   bool cache = false );

	private:
		AssetEntryMap m_assets;
		LoaderMap     m_loaders;
	};
}

#define g_content Gem::Content::Instance()

#include "gem/Content.inl"

#endif // ifndef GEM_CONTENT_HPP
