namespace Gem
{
    inline Rectangle::Rectangle()
        : m_x(0)
        , m_y(0)
        , m_width(0)
        , m_height(0)
    {
    }

    inline Rectangle::Rectangle(int x, int y, int width, int height)
        : m_x(x)
        , m_y(y)
        , m_width(width)
        , m_height(height)
    {
    }

    inline void Rectangle::Reset()
    {
        m_x = 0;
        m_y = 0;
        m_width = 0;
        m_height = 0;
    }

    inline void Rectangle::Reset(int x, int y, int width, int height)
    {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
    }

    inline Rectangle Rectangle::Intersect(const Rectangle& rectangle1, const Rectangle& rectangle2)
    {
        Rectangle rectangle;

        int num8 = rectangle1.m_x + rectangle1.m_width;
        int num7 = rectangle2.m_x + rectangle2.m_width;
        int num6 = rectangle1.m_y + rectangle1.m_height;
        int num5 = rectangle2.m_y + rectangle2.m_height;
        int num2 = (rectangle1.m_x > rectangle2.m_x) ? rectangle1.m_x : rectangle2.m_x;
        int num = (rectangle1.m_y > rectangle2.m_y) ? rectangle1.m_y : rectangle2.m_y;
        int num4 = (num8 < num7) ? num8 : num7;
        int num3 = (num6 < num5) ? num6 : num5;

        if ((num4 > num2) && (num3 > num))
        {
            rectangle.m_x = num2;
            rectangle.m_y = num;
            rectangle.m_width = num4 - num2;
            rectangle.m_height = num3 - num;

            return rectangle;
        }

        rectangle.m_x = 0;
        rectangle.m_y = 0;
        rectangle.m_width = 0;
        rectangle.m_height = 0;

        return rectangle;
    }

    inline void Rectangle::Intersect(const Rectangle& rectangle1, const Rectangle& rectangle2, Rectangle& result)
    {
        int num8 = rectangle1.m_x + rectangle1.m_width;
        int num7 = rectangle2.m_x + rectangle2.m_width;
        int num6 = rectangle1.m_y + rectangle1.m_height;
        int num5 = rectangle2.m_y + rectangle2.m_height;
        int num2 = (rectangle1.m_x > rectangle2.m_x) ? rectangle1.m_x : rectangle2.m_x;
        int num = (rectangle1.m_y > rectangle2.m_y) ? rectangle1.m_y : rectangle2.m_y;
        int num4 = (num8 < num7) ? num8 : num7;
        int num3 = (num6 < num5) ? num6 : num5;

        if ((num4 > num2) && (num3 > num))
        {
            result.m_x = num2;
            result.m_y = num;
            result.m_width = num4 - num2;
            result.m_height = num3 - num;
        }
        else
        {
            result.m_x = 0;
            result.m_y = 0;
            result.m_width = 0;
            result.m_height = 0;
        }
    }

    inline Rectangle Rectangle::Union(const Rectangle& rectangle1, const Rectangle& rectangle2)
    {
        Rectangle rectangle;

        int num6 = rectangle1.m_x + rectangle1.m_width;
        int num5 = rectangle2.m_x + rectangle2.m_width;
        int num4 = rectangle1.m_y + rectangle1.m_height;
        int num3 = rectangle2.m_y + rectangle2.m_height;
        int num2 = (rectangle1.m_x < rectangle2.m_x) ? rectangle1.m_x : rectangle2.m_x;
        int num = (rectangle1.m_y < rectangle2.m_y) ? rectangle1.m_y : rectangle2.m_y;
        int num8 = (num6 > num5) ? num6 : num5;
        int num7 = (num4 > num3) ? num4 : num3;

        rectangle.m_x = num2;
        rectangle.m_y = num;
        rectangle.m_width = num8 - num2;
        rectangle.m_height = num7 - num;

        return rectangle;
    }

    inline void Rectangle::Union(const Rectangle& rectangle1, const Rectangle& rectangle2, Rectangle& result)
    {
        int num6 = rectangle1.m_x + rectangle1.m_width;
        int num5 = rectangle2.m_x + rectangle2.m_width;
        int num4 = rectangle1.m_y + rectangle1.m_height;
        int num3 = rectangle2.m_y + rectangle2.m_height;
        int num2 = (rectangle1.m_x < rectangle2.m_x) ? rectangle1.m_x : rectangle2.m_x;
        int num = (rectangle1.m_y < rectangle2.m_y) ? rectangle1.m_y : rectangle2.m_y;
        int num8 = (num6 > num5) ? num6 : num5;
        int num7 = (num4 > num3) ? num4 : num3;

        result.m_x = num2;
        result.m_y = num;
        result.m_width = num8 - num2;
        result.m_height = num7 - num;
    }

    inline bool Rectangle::Intersects(const Rectangle& rectangle) const
    {
        return ((((rectangle.m_x < (m_x + m_width)) && (m_x < (rectangle.m_x + rectangle.m_width))) && (rectangle.m_y < (m_y + m_height))) && (m_y < (rectangle.m_y + rectangle.m_height)));
    }

    inline void Rectangle::Intersects(const Rectangle& rectangle, bool& result) const
    {
        result = ((((rectangle.m_x < (m_x + m_width)) && (m_x < (rectangle.m_x + rectangle.m_width))) && (rectangle.m_y < (m_y + m_height))) && (m_y < (rectangle.m_y + rectangle.m_height)));
    }

    inline int Rectangle::Bottom() const
    {
        return m_y + m_height;
    }

    inline Point Rectangle::Center() const
    {
        return Point(m_x + (m_width/2), m_y + (m_height/2));
    }

    inline bool Rectangle::Empty() const
    {
        return ((((m_width == 0) && (m_height == 0)) && (m_x == 0)) && (m_y == 0));
    }

    inline int Rectangle::Left() const
    {
        return m_x;
    }

    inline Point Rectangle::Location() const
    {
        return Point(m_x, m_y);
    }

    inline int Rectangle::Right() const
    {
        return m_x + m_width;
    }

    inline void Rectangle::SetLocation(const Point& location)
    {
        m_x = location.m_x;
        m_y = location.m_y;
    }

    inline int Rectangle::Top() const
    {
        return m_y;
    }

    inline int Rectangle::Visible() const
    {
        return m_width != 0 && m_height != 0;
    }

    inline bool Rectangle::Contains(int x, int y) const
    {
        return ((((m_x <= x) && (x < (m_x + m_width))) && (m_y <= y)) && (y < (m_y + m_height)));
    }

    inline bool Rectangle::Contains(const Point& point) const
    {
        return ((((m_x <= point.m_x) && (point.m_x < (m_x + m_width))) && (m_y <= point.m_y)) && (point.m_y < (m_y + m_height)));
    }

    inline void Rectangle::Contains(const Point& point, bool& result) const
    {
        result = ((((m_x <= point.m_x) && (point.m_x < (m_x + m_width))) && (m_y <= point.m_y)) && (point.m_y < (m_y + m_height)));
    }

    inline bool Rectangle::Contains(const Rectangle& rectangle) const
    {
        return ((((m_x <= rectangle.m_x) && ((rectangle.m_x + rectangle.m_width) <= (m_x + m_width))) && (m_y <= rectangle.m_y)) && ((rectangle.m_y + rectangle.m_height) <= (m_y + m_height)));
    }

    inline void Rectangle::Contains(const Rectangle& rectangle, bool& result) const
    {
        result = ((((m_x <= rectangle.m_x) && ((rectangle.m_x + rectangle.m_width) <= (m_x + m_width))) && (m_y <= rectangle.m_y)) && ((rectangle.m_y + rectangle.m_height) <= (m_y + m_height)));
    }

    inline void Rectangle::Inflate(int horizontalAmount, int verticalAmount)
    {
        m_x -= horizontalAmount;
        m_y -= verticalAmount;
        m_width += horizontalAmount * 2;
        m_height += verticalAmount * 2;
    }

    inline void Rectangle::Offset(int offsetX, int offsetY)
    {
        m_x += offsetX;
        m_y += offsetY;
    }

    inline void Rectangle::Offset(const Point& amount)
    {
        m_x += amount.m_x;
        m_y += amount.m_y;
    }
}
