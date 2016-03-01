#ifndef GEM_MATRIX_HPP
#define GEM_MATRIX_HPP

namespace Gem
{
    class Matrix
    {
    public:
        inline Matrix();

    public:
        inline Matrix& operator+=(const Matrix& matrix);
        inline Matrix& operator-=(const Matrix& matrix);
        inline Matrix& operator*=(const Matrix& matrix);
        inline Matrix& operator/=(const Matrix& matrix);

    public:
        static Matrix CreateRotationZ(float radians);
        static void CreateRotationZ(float radians,
                                    Matrix& result);
        static inline Matrix CreateScale(float scale);
        static void Multiply(const Matrix& matrix1,
                             const Matrix& matrix2,
                             Matrix& result);
        static inline void CreateTranslation(float xPosition,
                                             float yPosition,
                                             float zPosition,
                                             Matrix& result);

    public:
        float m_m11;
        float m_m12;
        float m_m13;
        float m_m14;
        float m_m21;
        float m_m22;
        float m_m23;
        float m_m24;
        float m_m31;
        float m_m32;
        float m_m33;
        float m_m34;
        float m_m41;
        float m_m42;
        float m_m43;
        float m_m44;
    };

    inline const Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
    inline const Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);
    inline const Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
    inline const Matrix operator/(const Matrix& matrix1, const Matrix& matrix2);
}

#include "gem/Matrix.inl"

#endif
