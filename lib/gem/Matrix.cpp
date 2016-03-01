#include "gem/Matrix.hpp"

#include <cmath>

namespace Gem
{
    Matrix Matrix::CreateRotationZ(float radians)
    {
        Matrix matrix;

        float num2 = cos(radians);
        float num = sin(radians);

        matrix.m_m11 = num2;
        matrix.m_m12 = num;
        matrix.m_m13 = 0.f;
        matrix.m_m14 = 0.f;
        matrix.m_m21 = -num;
        matrix.m_m22 = num2;
        matrix.m_m23 = 0.f;
        matrix.m_m24 = 0.f;
        matrix.m_m31 = 0.f;
        matrix.m_m32 = 0.f;
        matrix.m_m33 = 1.f;
        matrix.m_m34 = 0.f;
        matrix.m_m41 = 0.f;
        matrix.m_m42 = 0.f;
        matrix.m_m43 = 0.f;
        matrix.m_m44 = 1.f;

        return matrix;
    }

    void Matrix::CreateRotationZ(float radians, Matrix& result)
    {
        float num2 = cos(radians);
        float num = sin(radians);

        result.m_m11 = num2;
        result.m_m12 = num;
        result.m_m13 = 0.f;
        result.m_m14 = 0.f;
        result.m_m21 = -num;
        result.m_m22 = num2;
        result.m_m23 = 0.f;
        result.m_m24 = 0.f;
        result.m_m31 = 0.f;
        result.m_m32 = 0.f;
        result.m_m33 = 1.f;
        result.m_m34 = 0.f;
        result.m_m41 = 0.f;
        result.m_m42 = 0.f;
        result.m_m43 = 0.f;
        result.m_m44 = 1.f;
    }

    void Matrix::Multiply(const Matrix& matrix1, const Matrix& matrix2, Matrix& result)
    {
        float num16 = (((matrix1.m_m11 * matrix2.m_m11) + (matrix1.m_m12 * matrix2.m_m21)) + (matrix1.m_m13 * matrix2.m_m31)) + (matrix1.m_m14 * matrix2.m_m41);
        float num15 = (((matrix1.m_m11 * matrix2.m_m12) + (matrix1.m_m12 * matrix2.m_m22)) + (matrix1.m_m13 * matrix2.m_m32)) + (matrix1.m_m14 * matrix2.m_m42);
        float num14 = (((matrix1.m_m11 * matrix2.m_m13) + (matrix1.m_m12 * matrix2.m_m23)) + (matrix1.m_m13 * matrix2.m_m33)) + (matrix1.m_m14 * matrix2.m_m43);
        float num13 = (((matrix1.m_m11 * matrix2.m_m14) + (matrix1.m_m12 * matrix2.m_m24)) + (matrix1.m_m13 * matrix2.m_m34)) + (matrix1.m_m14 * matrix2.m_m44);
        float num12 = (((matrix1.m_m21 * matrix2.m_m11) + (matrix1.m_m22 * matrix2.m_m21)) + (matrix1.m_m23 * matrix2.m_m31)) + (matrix1.m_m24 * matrix2.m_m41);
        float num11 = (((matrix1.m_m21 * matrix2.m_m12) + (matrix1.m_m22 * matrix2.m_m22)) + (matrix1.m_m23 * matrix2.m_m32)) + (matrix1.m_m24 * matrix2.m_m42);
        float num10 = (((matrix1.m_m21 * matrix2.m_m13) + (matrix1.m_m22 * matrix2.m_m23)) + (matrix1.m_m23 * matrix2.m_m33)) + (matrix1.m_m24 * matrix2.m_m43);
        float num9 = (((matrix1.m_m21 * matrix2.m_m14) + (matrix1.m_m22 * matrix2.m_m24)) + (matrix1.m_m23 * matrix2.m_m34)) + (matrix1.m_m24 * matrix2.m_m44);
        float num8 = (((matrix1.m_m31 * matrix2.m_m11) + (matrix1.m_m32 * matrix2.m_m21)) + (matrix1.m_m33 * matrix2.m_m31)) + (matrix1.m_m34 * matrix2.m_m41);
        float num7 = (((matrix1.m_m31 * matrix2.m_m12) + (matrix1.m_m32 * matrix2.m_m22)) + (matrix1.m_m33 * matrix2.m_m32)) + (matrix1.m_m34 * matrix2.m_m42);
        float num6 = (((matrix1.m_m31 * matrix2.m_m13) + (matrix1.m_m32 * matrix2.m_m23)) + (matrix1.m_m33 * matrix2.m_m33)) + (matrix1.m_m34 * matrix2.m_m43);
        float num5 = (((matrix1.m_m31 * matrix2.m_m14) + (matrix1.m_m32 * matrix2.m_m24)) + (matrix1.m_m33 * matrix2.m_m34)) + (matrix1.m_m34 * matrix2.m_m44);
        float num4 = (((matrix1.m_m41 * matrix2.m_m11) + (matrix1.m_m42 * matrix2.m_m21)) + (matrix1.m_m43 * matrix2.m_m31)) + (matrix1.m_m44 * matrix2.m_m41);
        float num3 = (((matrix1.m_m41 * matrix2.m_m12) + (matrix1.m_m42 * matrix2.m_m22)) + (matrix1.m_m43 * matrix2.m_m32)) + (matrix1.m_m44 * matrix2.m_m42);
        float num2 = (((matrix1.m_m41 * matrix2.m_m13) + (matrix1.m_m42 * matrix2.m_m23)) + (matrix1.m_m43 * matrix2.m_m33)) + (matrix1.m_m44 * matrix2.m_m43);
        float num = (((matrix1.m_m41 * matrix2.m_m14) + (matrix1.m_m42 * matrix2.m_m24)) + (matrix1.m_m43 * matrix2.m_m34)) + (matrix1.m_m44 * matrix2.m_m44);

        result.m_m11 = num16;
        result.m_m12 = num15;
        result.m_m13 = num14;
        result.m_m14 = num13;
        result.m_m21 = num12;
        result.m_m22 = num11;
        result.m_m23 = num10;
        result.m_m24 = num9;
        result.m_m31 = num8;
        result.m_m32 = num7;
        result.m_m33 = num6;
        result.m_m34 = num5;
        result.m_m41 = num4;
        result.m_m42 = num3;
        result.m_m43 = num2;
        result.m_m44 = num;
    }
}
