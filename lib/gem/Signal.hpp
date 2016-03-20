#ifndef GEM_SIGNAL_HPP
#define GEM_SIGNAL_HPP

#include <functional>
#include <forward_list>

#define GEM_SIGNAL(signal, args) \
  public:   \
    inline void Add##signal##Listener(  \
      const std::function<void##args > &listener)  \
{ \
  m_##signal##Listeners.push_front(listener); \
} \
  \
protected:  \
 std::forward_list<std::function<void##args > >	\
 	m_##signal##Listeners;

#define GEM_EMIT(signal, args)	\
 	for (auto func : m_##signal##Listeners)	\
 		func##args;

#define GEM_CONNECT0(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer)));	\
 }	\

#define GEM_CONNECT1(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer),	\
 			std::placeholders::_1));	\
 }	\

#define GEM_CONNECT2(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer),	\
 			std::placeholders::_1,		\
 			std::placeholders::_2));	\
 }	\

#define GEM_CONNECT3(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer),	\
 			std::placeholders::_1,		\
 			std::placeholders::_2,		\
 			std::placeholders::_3));	\
 }	\

#define GEM_CONNECT4(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer),	\
 			std::placeholders::_1,		\
 			std::placeholders::_2,		\
 			std::placeholders::_3,		\
 			std::placeholders::_4));	\
 }	\
 
#define GEM_CONNECT5(emitter, signal, observer, slot)	\
 {	\
 		GEM_ASSERT((emitter) != nullptr);	\
 		(emitter)->Add##signal##Listener(std::bind((slot),	\
 			(observer),	\
 			std::placeholders::_1,		\
 			std::placeholders::_2,		\
 			std::placeholders::_3,		\
 			std::placeholders::_4,		\
 			std::placeholders::_5));	\
 }	\

#endif //GEM_SIGNAL_HPP
