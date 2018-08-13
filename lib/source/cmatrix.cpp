#include "matrix.h"

namespace LinAlg
{
       
namespace Matrix
{
    // ================================================
    // CONSTRUCTORS AND DESTRUCTORS
    // ================================================
    
    // Default Constructor
    template<typename T>
    CMatrix<T>::CMatrix(size_t r, size_t c) :
        m_rows(r),
        m_cols(c)
    {
        m_totalSize = m_rows * m_cols;
        m_ptValues = new T*[r];
        for (int i = 0; i < r; i++)
            m_ptValues[i] = new T[c];
        m_type = EMatrixTypes::None;
    }

    // Constructor for special type Matrix
    template<typename T>
    CMatrix<T>::CMatrix(EMatrixTypes type, size_t n) :
        m_rows(n),
        m_cols(n),
        m_type(type)
    {
        m_totalSize = m_rows * m_cols;
        m_ptValues = new T*[n];
        for (int i = 0; i < n, i++)
            m_ptValues[i] = new T[n];
        
        // To Do
        switch(type)
        {
            case EMatrixTypes::None : 
                // To Do
                break;
            case EMatrixTypes::Quadratic :
                // To Do
                break;
            case EMatrixTypes::Identity :
                // To Do
                break;
            case EMatrixTypes::Zero :
                // To Do
                break;
        }
    }

    // Copy Constructor
    template<typename T>
    CMatrix<T>& CMatrix::operator=(const CMatrix<T>& rhs) 
    {
        if (&rhs == this) {
            return *this;
        }
        if (m_totalSize == rhs.m_totalSize) {
            std::memcpy(m_ptValues, rhs.m_ptValues, rhs.m_totalSize * sizeof(T));
        } else {
            delete[] m_ptValues;
            m_ptValues = new T[rhs.m_totalSize]();
            std::memcpy(m_ptValues, rhs.m_ptValues, rhs.m_totalSize * sizeof(T));
        }
        m_rows      = rhs.m_rows;
        m_columns   = rhs.m_columns;
        m_totalSize = rhs.m_totalSize;

        return *this;
    }

    // Desctuctor
    template<typename T>
    CMatrix<T>::~CMatrix()
    {
        if (m_ptValues) 
        {
            delete[] m_ptValues;
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

} // Matrix

} // LinAlg


