#ifndef GEM_INPUT_HPP
#define GEM_INPUT_HPP

#include <boost/variant.hpp>

namespace Gem
{
    enum class KeyState
    {
        Down,
        Up
    };

    enum class TouchAction
    {
        Down,
        Move,
        Up,
    };

    struct TouchPoint
    {
        TouchAction m_action;
        int m_id;
        int m_x;
        int m_y;
    };

    struct KeyboardInput
    {
        KeyState m_state;
        int m_code;
    };

    struct TouchInput
    {
        TouchAction m_action;
        TouchPoint m_point;
    };

    typedef boost::variant<KeyboardInput, TouchInput> Input;
}

#endif
