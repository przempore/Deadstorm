#ifndef GEM_ASSERT_HPP
#define GEM_ASSERT_HPP

#include "gem/System.hpp"

#if defined( _DEBUG )
 # define GEM_ASSERT( expression )									 \
	do																 \
	{																 \
		if( !( expression ) )										 \
		{															 \
			Gem::System::ReportFailure( "[ASSERT] Assertion failed", \
										#expression,				 \
										__FILE__,					 \
										__LINE__ );					 \
			Gem::System::Abort();									 \
		}															 \
	}																 \
	while( 0 )
#else
 # define GEM_ASSERT( expression ) do { ( void )sizeof( expression ); }	\
	while( 0 )
#endif

#endif // ifndef GEM_ASSERT_HPP
