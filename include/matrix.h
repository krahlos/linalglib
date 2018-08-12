#ifndef __CMATRIX_H
#define __CMATRIX_H

#include <math.h>
#include <vector.h>

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
        
        T       *m_ptValues;
        size_t  m_totalSize;
        size_t  m_rows;
        size_t  m_cols;

        EMatrixTypes m_type;
        
        public:

        // ================================================
        // CONSTRUCTORS AND DESTRUCTORS
        // ================================================

        CMatrix(size_t r, size_t c); // default constructor
        CMatrix(EMatrixTypes type, size_t n) // constructor for special type matrix

        CMatrix(const CMatrix<T> &rhs); // copy constructor

        ~CMatrix(); // destructor

        // ================================================
        // OPERATORS
        // ================================================

        CMatrix<T>& operator= (const CMatrix<T>& rhs); // copy assignment operator

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

    };
    
    
} // Matrix

} // LinAlg

#endif // __CMATRIX_H