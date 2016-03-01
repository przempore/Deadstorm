#include "gem/Vector2.hpp"

#include "gem/Matrix.hpp"

namespace Gem
{
    Vector2 Vector2::Transform(const Vector2& position, const Matrix& matrix)
    {
        return Vector2(((position.m_x*matrix.m_m11) + (position.m_y*matrix.m_m21)) + matrix.m_m41,
                       ((position.m_y*matrix.m_m12) + (position.m_y*matrix.m_m22)) + matrix.m_m42);
    }

    void Vector2::Transform(const Vector2& position, const Matrix& matrix, Vector2& result)
    {
        float num2 = ((position.m_x * matrix.m_m11) + (position.m_y * matrix.m_m21)) + matrix.m_m41;
        float num = ((position.m_x * matrix.m_m12) + (position.m_y * matrix.m_m22)) + matrix.m_m42;

        result.m_x = num2;
        result.m_y = num;
    }

    const Vector2 Vector2::s_one(1.f, 1.f);
    const Vector2 Vector2::s_zero(0.f, 0.f);
}
