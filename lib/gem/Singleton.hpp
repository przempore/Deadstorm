#ifndef GEM_SINGLETON_HPP
#define GEM_SINGLETON_HPP

#include "gem/Assert.hpp"

#include <boost/noncopyable.hpp>

namespace Gem
{
	template< class T_ >
	class Singleton : private boost::noncopyable
	{
	public:
		inline Singleton();
		inline ~Singleton();

	public:
		static inline T_& Instance();
		static inline T_* InstancePtr();

	private:
		static T_* s_instance;
	};

	template< class T_ >
	T_ * Singleton< T_ >::s_instance = nullptr;
}

#include "gem/Singleton.inl"

#endif // ifndef GEM_SINGLETON_HPP
