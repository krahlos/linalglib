#ifndef __CVECTOR_H
#define __CVECTOR_H

#include <math.h>

namespace LinAlg
{

namespace Vector 
{

    enum EVectorTypes
    {
        None = 0,
        Zero,
        OneHot
    };

    template <typename T>
    class CVector
    {
        private:
        
        T       *m_ptValues;
        size_t  m_dim;

        EVectorTypes m_type;

        public:

        // ================================================
        // CONSTRUCTORS AND DESTRUCTORS
        // ================================================

        CVector(size_t dim); // default constructor
        CVector(size_t dim, EVectorTypes type); // constructor for special type vector

        CVector(const CVector<T> &rhs); // copy constructor

        ~CVector(); // destructor

        // ================================================
        // OPERATORS
        // ================================================

        CVector<T>& operator= (const CVector<T>& rhs); // copy assignment operator

        CVector<T>  operator+ (const CVector<T>& rhs);
        CVector<T>& operator+=(const CVector<T>& rhs);

        CVector<T>  operator- (const CVector<T>& rhs);
        CVector<T>& operator-=(const CVector<T>& rhs);

        CVector<T>  operator* (const CVector<T>& rhs);
        CVector<T>& operator*=(const CVector<T>& rhs);

        // ================================================
        // FUNCTIONS
        // ================================================

        const size_t getDim() { return m_dim; }
        
        const EVectorTypes getType() { return m_type; } 

    };

} // Vector

} // Linalg

#endif // __CVECTOR_H