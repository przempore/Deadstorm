#define GEM_MATRIX_OP_EQ_IMPL(op) \
    m_m11 op##= matrix.m_m11; \
    m_m12 op##= matrix.m_m12; \
    m_m13 op##= matrix.m_m13; \
    m_m14 op##= matrix.m_m14; \
    m_m21 op##= matrix.m_m21; \
    m_m22 op##= matrix.m_m22; \
    m_m23 op##= matrix.m_m23; \
    m_m24 op##= matrix.m_m24; \
    m_m31 op##= matrix.m_m31; \
    m_m32 op##= matrix.m_m32; \
    m_m33 op##= matrix.m_m33; \
    m_m34 op##= matrix.m_m34; \
    m_m41 op##= matrix.m_m41; \
    m_m42 op##= matrix.m_m42; \
    m_m43 op##= matrix.m_m43; \
    m_m44 op##= matrix.m_m44

namespace Gem
{
    inline Matrix::Matrix()
        : m_m11(0.f)
        , m_m12(0.f)
        , m_m13(0.f)
        , m_m14(0.f)
        , m_m21(0.f)
        , m_m22(0.f)
        , m_m23(0.f)
        , m_m24(0.f)
        , m_m31(0.f)
        , m_m32(0.f)
        , m_m33(0.f)
        , m_m34(0.f)
        , m_m41(0.f)
        , m_m42(0.f)
        , m_m43(0.f)
        , m_m44(0.f)
    {
    }

    inline Matrix& Matrix::operator+=(const Matrix& matrix)
    {
        GEM_MATRIX_OP_EQ_IMPL(+);

        return *this;
    }

    inline Matrix& Matrix::operator-=(const Matrix& matrix)
    {
        GEM_MATRIX_OP_EQ_IMPL(-);

        return *this;
    }

    inline Matrix& Matrix::operator*=(const Matrix& matrix)
    {
        GEM_MATRIX_OP_EQ_IMPL(*);

        return *this;
    }

    inline Matrix& Matrix::operator/=(const Matrix& matrix)
    {
        GEM_MATRIX_OP_EQ_IMPL(/);

        return *this;
    }

    inline Matrix Matrix::CreateScale(float scale)
    {
        Matrix matrix;

        matrix.m_m11 = scale;
        matrix.m_m12 = 0.f;
        matrix.m_m13 = 0.f;
        matrix.m_m14 = 0.f;
        matrix.m_m21 = 0.f;
        matrix.m_m22 = scale;
        matrix.m_m23 = 0.f;
        matrix.m_m24 = 0.f;
        matrix.m_m31 = 0.f;
        matrix.m_m32 = 0.f;
        matrix.m_m33 = scale;
        matrix.m_m34 = 0.f;
        matrix.m_m41 = 0.f;
        matrix.m_m42 = 0.f;
        matrix.m_m43 = 0.f;
        matrix.m_m44 = 1.f;

        return matrix;
    }

    inline void Matrix::CreateTranslation(float xPosition, float yPosition, float zPosition, Matrix& result)
    {
        result.m_m11 = 1.f;
        result.m_m12 = 0.f;
        result.m_m13 = 0.f;
        result.m_m14 = 0.f;
        result.m_m21 = 0.f;
        result.m_m22 = 1.f;
        result.m_m23 = 0.f;
        result.m_m24 = 0.f;
        result.m_m31 = 0.f;
        result.m_m32 = 0.f;
        result.m_m33 = 1.f;
        result.m_m34 = 0.f;
        result.m_m41 = xPosition;
        result.m_m42 = yPosition;
        result.m_m43 = zPosition;
        result.m_m44 = 1.f;
    }

    inline const Matrix operator+(const Matrix& matrix1, const Matrix& matrix2)
    {
        return Matrix(matrix1) += matrix2;
    }

    inline const Matrix operator-(const Matrix& matrix1, const Matrix& matrix2)
    {
        return Matrix(matrix1) -= matrix2;
    }

    inline const Matrix operator*(const Matrix& matrix1, const Matrix& matrix2)
    {
        return Matrix(matrix1) *= matrix2;
    }

    inline const Matrix operator/(const Matrix& matrix1, const Matrix& matrix2)
    {
        return Matrix(matrix1) /= matrix2;
    }
}

#undef GEM_MATRIX_OP_EQ_IMPL
