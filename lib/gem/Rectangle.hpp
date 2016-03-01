#ifndef GEM_RECTANGLE_HPP
#define GEM_RECTANGLE_HPP

#include "gem/Point.hpp"

namespace Gem
{
    class Rectangle
    {
    public:
        inline Rectangle();
        inline Rectangle(int x, int y, int width, int height);

    public:
        inline void Reset();
        inline void Reset(int x, int y, int width, int height);

    public:
        static inline Rectangle Intersect(const Rectangle& rectangle1,
                                          const Rectangle& rectangle2);
        static inline void Intersect(const Rectangle& rectangle1,
                                     const Rectangle& rectangle2,
                                     Rectangle& result);
        static inline Rectangle Union(const Rectangle& rectangle1,
                                      const Rectangle& rectangle2);
        static inline void Union(const Rectangle& rectangle1,
                                 const Rectangle& rectangle2,
                                 Rectangle& result);

    public:
        inline int Bottom() const;
        inline Point Center() const;
        inline bool Empty() const;
        inline int Left() const;
        inline Point Location() const;
        inline int Right() const;
        inline void SetLocation(const Point& location);
        inline int Top() const;
        inline int Visible() const;

    public:
        inline bool Contains(int x, int y) const;
        inline bool Contains(const Point& point) const;
        inline void Contains(const Point& point, bool& result) const;
        inline bool Contains(const Rectangle& rectangle) const;
        inline void Contains(const Rectangle& rectangle, bool& result) const;
        inline void Inflate(int horizontalAmount, int verticalAmount);
        inline bool Intersects(const Rectangle& rectangle) const;
        inline void Intersects(const Rectangle& rectangle, bool& result) const;
        inline void Offset(int offsetX, int offsetY);
        inline void Offset(const Point& amount);

    public:
        static const Rectangle s_empty;

    public:
        int m_x;
        int m_y;
        int m_width;
        int m_height;
    };
}

#include "gem/Rectangle.inl"

#endif
