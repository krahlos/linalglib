#include "cmatrix.h"

namespace LinAlg
{

namespace Matrix
{

// ================================================
// CONSTRUCTORS AND DESTRUCTORS
// ================================================

// Default Constructor
template <typename T>
CMatrix<T>::CMatrix(size_t r, size_t c) : m_rows(r),
                                          m_cols(c)
{
    m_totalSize = m_rows * m_cols;

    m_ptMatrix = malloc(m_rows * sizeof(T *));
    for (size_t i = 0; i < m_rows; i++)
        m_ptMatrix[i] = malloc(m_cols * sizeof(T));

    m_type = EMatrixTypes::None;
}

// Constructor for special type Matrix
template <typename T>
CMatrix<T>::CMatrix(EMatrixTypes type, size_t n) : m_rows(n),
                                                   m_cols(n),
                                                   m_type(type)
{
    m_totalSize = m_rows * m_cols;

    m_ptMatrix = malloc(m_rows * sizeof(T *));
    for (size_t i = 0; i < m_rows; i++)
        m_ptMatrix[i] = malloc(m_cols * sizeof(T));

    // To Do
    switch (type)
    {
    case EMatrixTypes::None:
        // To Do
        break;
    case EMatrixTypes::Quadratic:
        // To Do
        break;
    case EMatrixTypes::Identity:
        // To Do
        break;
    case EMatrixTypes::Zero:
        // To Do
        break;
    }
}

// ================================================
// OPERATORS
// ================================================

// ================================================
// FUNCTIONS
// ================================================

// ================================================
// MATHEMATICAL FUNCTIONS
// ================================================

} // namespace Matrix

} // namespace LinAlg
