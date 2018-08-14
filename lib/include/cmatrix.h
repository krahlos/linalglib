#ifndef __CMATRIX_H
#define __CMATRIX_H

#include <math.h>
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
        
        T       **m_ptValues;
        size_t  m_totalSize;
        size_t  m_rows;
        size_t  m_cols;

        EMatrixTypes m_type;
        
        public:

        // ================================================
        // CONSTRUCTORS AND DESTRUCTORS
        // ================================================

        /// Default Constructor
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
        CMatrix(const CMatrix<T> &rhs) :
            m_rows(rhs.m_rows),
            m_cols(rhs.m_cols) 
        {
            m_totalSize = rhs.m_totalSize;
            m_ptValues = new T[rhs.m_totalSize]();
            std::memcpy(m_ptValues, rhs.m_ptValues, rhs.m_totalSize * sizeof(T));
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
        CMatrix<T>& operator= (const CMatrix<T>& rhs);

        CMatrix<T>  operator+ (const CMatrix<T>& rhs);
        CMatrix<T>& operator+=(const CMatrix<T>& rhs);

        CMatrix<T>  operator- (const CMatrix<T>& rhs);
        CMatrix<T>& operator-=(const CMatrix<T>& rhs);

        CMatrix<T>  operator* (const CMatrix<T>& rhs);
        CMatrix<T>& operator*=(const CMatrix<T>& rhs);

        // ================================================
        // FUNCTIONS
        // ================================================

        const size_t getRowDim() { return m_rows; }
        const size_t getColDim() { return m_cols; }
        
        const EMatrixTypes getType() { return m_type; }

        // ================================================
        // MATHEMATICAL FUNCTIONS
        // ================================================

    };
    
    
} // Matrix

} // LinAlg

#endif // __CMATRIX_H