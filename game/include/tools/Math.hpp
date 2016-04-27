#ifndef DEADSTORM_MATH_HPP
#define DEADSTORM_MATH_HPP

template <class T>
inline bool isEqual(T a, T b, T c)
{
    T diff = a - b;
    if (diff < 0)
        diff = -diff;

    return diff < c;
}

#endif //DEADSTORM_MATH_HPP
