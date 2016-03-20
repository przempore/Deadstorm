#ifndef GEM_ACTION_HPP
#define GEM_ACTION_HPP

#include <memory>
#include <boost/core/noncopyable.hpp>

namespace Gem
{
    class Action;

    typedef std::shared_ptr<Action> ActionPtr;
    typedef std::weak_ptr<Action> ActionWPtr;
    typedef std::shared_ptr<const Action> ConstActionPtr;
    typedef std::weak_ptr<const Action> ConstActionWPtr;

    class Action : private boost::noncopyable
    {
    public:
        inline virtual ~Action() {}

    public:
        virtual void Reset() = 0;
        virtual void Update(float dt) = 0;
        virtual ActionPtr Reversed() const = 0;
    };
}


#endif //GEM_ACTION_HPP
