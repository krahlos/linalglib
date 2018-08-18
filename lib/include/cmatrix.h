#ifndef __CMATRIX_H
#define __CMATRIX_H

#include <math.h>
#include <stdlib.h>
#include <cvector.h>

namespace LinAlg
{

namespace Matrix
{
enum EMatrixTypes
{
    None = 0,
    Quadratic,
    Identity,
    Zero
};

template <typename T>
class CMatrix
{
  private:
    T **m_ptValues;
    size_t m_totalSize;
    size_t m_rows;
    size_t m_cols;

    EMatrixTypes m_type;

  public:
    // ================================================
    // CONSTRUCTORS AND DESTRUCTORS
    // ================================================

    // Default Constructor
    CMatrix(size_t r, size_t c);

    // Constructor for special type Matrix
    CMatrix(EMatrixTypes type, size_t n);

    // Copy Constructor
    CMatrix(const CMatrix<T> &rhs) : m_rows(rhs.m_rows),
                                     m_cols(rhs.m_cols)
    {
        m_totalSize = rhs.m_totalSize;
        m_ptValues = new T[rhs.m_totalSize]();

        m_ptValues = malloc(m_rows * sizeof(T *));
        for (size_t i = 0; i < m_rows; i++)
            m_ptValues[i] = malloc(m_cols * sizeof(T));
    }

    // Destructor
    ~CMatrix()
    {
        if (m_ptValues)
        {
            delete[] m_ptValues;
        }
    }

    // ================================================
    // OPERATORS
    // ================================================

    // copy assignment operator
    CMatrix<T> &operator=(const CMatrix<T> &rhs);

    CMatrix<T> operator+(const CMatrix<T> &rhs);
    CMatrix<T> &operator+=(const CMatrix<T> &rhs);

    CMatrix<T> operator-(const CMatrix<T> &rhs);
    CMatrix<T> &operator-=(const CMatrix<T> &rhs);

    CMatrix<T> operator*(const CMatrix<T> &rhs);
    CMatrix<T> &operator*=(const CMatrix<T> &rhs);

    // ================================================
    // FUNCTIONS
    // ================================================

    size_t getRowDim() { return m_rows; }
    size_t getColDim() { return m_cols; }

    EMatrixTypes getType() { return m_type; }

    // ================================================
    // MATHEMATICAL FUNCTIONS
    // ================================================
};

} // namespace Matrix

} // namespace LinAlg

#endif // __CMATRIX_H
