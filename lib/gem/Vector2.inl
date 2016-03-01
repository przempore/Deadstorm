#define GEM_VECTOR2_OP_EQ_IMPL(op) \
    m_x op##= vector.m_x; \
    m_y op##= vector.m_y;

#define GEM_VECTOR2_OP_EQ_IMPL2(op) \
    m_x op##= value; \
    m_y op##= value;

namespace Gem
{
    inline Vector2::Vector2()
    {
    }

    inline Vector2::Vector2(float x, float y)
        : m_x(x)
        , m_y(y)
    {
    }

    inline void Vector2::Reset()
    {
        m_x = 0.f;
        m_y = 0.f;
    }

    inline void Vector2::Reset(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    inline Vector2& Vector2::operator+=(const Vector2& vector)
    {
        GEM_VECTOR2_OP_EQ_IMPL(+);

        return *this;
    }

    inline Vector2& Vector2::operator-=(const Vector2& vector)
    {
        GEM_VECTOR2_OP_EQ_IMPL(-);

        return *this;
    }

    inline Vector2& Vector2::operator*=(const Vector2& vector)
    {
        GEM_VECTOR2_OP_EQ_IMPL(*);

        return *this;
    }

    inline Vector2& Vector2::operator/=(const Vector2& vector)
    {
        GEM_VECTOR2_OP_EQ_IMPL(/);

        return *this;
    }

    inline Vector2& Vector2::operator+=(float value)
    {
        GEM_VECTOR2_OP_EQ_IMPL2(+);

        return *this;
    }

    inline Vector2& Vector2::operator-=(float value)
    {
        GEM_VECTOR2_OP_EQ_IMPL2(-);

        return *this;
    }

    inline Vector2& Vector2::operator*=(float value)
    {
        GEM_VECTOR2_OP_EQ_IMPL2(*);

        return *this;
    }

    inline Vector2& Vector2::operator/=(float value)
    {
        GEM_VECTOR2_OP_EQ_IMPL2(/);

        return *this;
    }

    inline const Vector2 operator+(const Vector2& vector1, const Vector2& vector2)
    {
        return Vector2(vector1) += vector2;
    }

    inline const Vector2 operator-(const Vector2& vector1, const Vector2& vector2)
    {
        return Vector2(vector1) -= vector2;
    }

    inline const Vector2 operator*(const Vector2& vector1, const Vector2& vector2)
    {
        return Vector2(vector1) *= vector2;
    }

    inline const Vector2 operator/(const Vector2& vector1, const Vector2& vector2)
    {
        return Vector2(vector1) /= vector2;
    }

    inline const Vector2 operator+(const Vector2& vector, float value)
    {
        return Vector2(vector) += value;
    }

    inline const Vector2 operator-(const Vector2& vector, float value)
    {
        return Vector2(vector) -= value;
    }

    inline const Vector2 operator*(const Vector2& vector, float value)
    {
        return Vector2(vector) *= value;
    }

    inline const Vector2 operator/(const Vector2& vector, float value)
    {
        return Vector2(vector) /= value;
    }

    inline const Vector2 operator+(float value, const Vector2& vector)
    {
        return Vector2(vector) += value;
    }

    inline const Vector2 operator-(float value, const Vector2& vector)
    {
        return Vector2(vector) -= value;
    }

    inline const Vector2 operator*(float value, const Vector2& vector)
    {
        return Vector2(vector) *= value;
    }

    inline const Vector2 operator/(float value, const Vector2& vector)
    {
        return Vector2(vector) /= value;
    }
}

#undef GEM_VECTOR2_OP_EQ_IMPL
#undef GEM_VECTOR2_OP_EQ_IMPL2
