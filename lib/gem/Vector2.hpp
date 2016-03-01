#ifndef GEM_VECTOR_2_HPP
#define GEM_VECTOR_2_HPP

namespace Gem
{
    class Matrix;

    class Vector2
    {
    public:
        inline Vector2();
        inline Vector2(float x, float y);

    public:
        inline void Reset();
        inline void Reset(float x, float y);

    public:
        inline Vector2& operator+=(const Vector2& vector);
        inline Vector2& operator-=(const Vector2& vector);
        inline Vector2& operator*=(const Vector2& vector);
        inline Vector2& operator/=(const Vector2& vector);
        inline Vector2& operator+=(float value);
        inline Vector2& operator-=(float value);
        inline Vector2& operator*=(float value);
        inline Vector2& operator/=(float value);

    public:
        static Vector2 Transform(const Vector2& position,
                                 const Matrix& matrix);
        static void Transform(const Vector2& position,
                              const Matrix& matrix,
                              Vector2& result);

    public:
        static const Vector2 s_one;
        static const Vector2 s_zero;

    public:
        float m_x{0.f};
        float m_y{0.f};
    };

    inline const Vector2 operator+(const Vector2& vector1, const Vector2& vector2);
    inline const Vector2 operator-(const Vector2& vector1, const Vector2& vector2);
    inline const Vector2 operator*(const Vector2& vector1, const Vector2& vector2);
    inline const Vector2 operator/(const Vector2& vector1, const Vector2& vector2);
    inline const Vector2 operator+(const Vector2& vector, float value);
    inline const Vector2 operator-(const Vector2& vector, float value);
    inline const Vector2 operator*(const Vector2& vector, float value);
    inline const Vector2 operator/(const Vector2& vector, float value);
    inline const Vector2 operator+(float value, const Vector2& vector);
    inline const Vector2 operator-(float value, const Vector2& vector);
    inline const Vector2 operator*(float value, const Vector2& vector);
    inline const Vector2 operator/(float value, const Vector2& vector);
}

#include "gem/Vector2.inl"

#endif
