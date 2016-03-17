#ifndef GEM_STATE_HPP
#define GEM_STATE_HPP

#include <boost/noncopyable.hpp>

#include <memory>

namespace Gem
{
    class State : boost::noncopyable
    {
    public:
        virtual ~State() {}

    public:
        virtual void OnEnter(void* owner, int previousStateId) = 0;
        virtual void OnExit(void* owner, int nextStateId) = 0;
        virtual void OnSuspend(void* owner, int pushedStateId) = 0;
        virtual void OnResume(void* owner, int poppedStateId) = 0;
    };
    typedef std::shared_ptr<State> StatePtr;
    typedef std::shared_ptr<const State> ConstStatePtr;
}


#endif //GEM_STATE_HPP