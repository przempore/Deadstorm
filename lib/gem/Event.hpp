#ifndef GEM_EVENT_HPP
#define GEM_EVENT_HPP

#include <boost/variant.hpp>

namespace Gem
{
    struct FocusEvent
    {
        bool m_gain;
    };

    struct ResizeEvent
    {
        int m_displayWidth;
        int m_displayHeight;
    };

    typedef boost::variant<FocusEvent, ResizeEvent> Event;
}

#endif
