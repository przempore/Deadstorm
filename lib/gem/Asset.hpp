#ifndef GEM_ASSET_HPP
#define GEM_ASSET_HPP

#include <boost/noncopyable.hpp>

#include <memory>

namespace Gem
{
    class Asset : private boost::noncopyable
    {
    public:
	    virtual ~Asset() = 0;

    public:
	    virtual void Initialize();
    };

    typedef std::shared_ptr<Asset> AssetPtr;
    typedef std::weak_ptr<Asset> AssetWPtr;
}

#endif
