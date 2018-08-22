#include "cvector.h"

namespace LinAlg
{

namespace Vector
{

// ================================================
// [PUBLIC] CONSTRUCTORS AND DESTRUCTORS
// ================================================

// Default Constructor
template <typename T>
CVector<T>::CVector(size_t dim) : m_dim(dim)
{
    m_ptVector = malloc(dim * sizeof(T));
    m_type = EVectorTypes::None;
}

/* TO DO
// Constructor for special type Vector
template <typename T>
CVector<T>::CVector(size_t dim, EVectorTypes type) : m_dim(dim),
                                                     m_type(type)
{
    m_ptVector = malloc(dim * sizeof(T));

    // To Do
    switch (type)
    {
    case EVectorTypes::None:
        // To Do
        break;
    case EVectorTypes::OneHot:
        // To Do
        break;
    case EVectorTypes::Zero:
        // To Do
        break;
    default:
        // To Do
        break;
    }
}
*/

template <typename T>
CVector<T>::CVector(T &ptVector, size_t dim) : m_dim(dim)
{
    m_ptVector = ptVector;
}

// ================================================
// [PUBLIC] OPERATORS
// ================================================

// copy assignment operator
template <typename T>
CVector<T> &CVector<T>::operator=(const CVector<T> &vec)
{
    if(this != &vec)
    {
        delete [] m_ptVector;
        copy(vec);
    }

    return *this;
}

template <typename T>
T &CVector<T>::operator()(size_t idx)
{
    if (idx > m_dim)
        throw std::out_of_range("Index out of range.");

    return m_ptVector[idx];
}

template <typename T>
T CVector<T>::operator()(size_t idx) const
{
    if (idx > m_dim)
        throw std::out_of_range("Index out of range.");

    return m_ptVector[idx];
}

template <typename T>
bool CVector<T>::operator==(const CVector<T> &vec) const
{
    if ((m_dim != vec.m_dim))
    {
        return false;
    }

    for (size_t i = 0; i < m_dim; i++)
    {
        if (m_ptVector[i] != vec.m_ptVector[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool CVector<T>::operator!=(const CVector<T> &vec) const
{
    return !((*this) == vec);
}

template <typename T>
CVector<T> CVector<T>::operator+(const CVector<T> &vec)
{
    if (m_dim != vec.m_dim)
        throw std::range_error("Dimensions must be the same");

    CVector<T> tmp(*this);

    for(size_t i = 0; i < m_dim; i++)
    {
        tmp.m_ptVector[i] += vec.m_ptVector[i];
    }

    return tmp;
}

template <typename T>
CVector<T> &CVector<T>::operator+=(const CVector<T> &vec)
{
    if (m_dim != vec.m_dim)
        throw std::range_error("Dimensions must be the same");
    
    for(size_t i = 0; i < m_dim; i++)
    {
        m_ptVector[i] += vec.m_ptVector[i];
    }

    return *this;
}

template <typename T>
CVector<T> CVector<T>::operator-(const CVector<T> &vec)
{
    if (m_dim != vec.m_dim)
        throw std::range_error("Dimensions must be the same");

    CVector<T> tmp(*this);

    for(size_t i = 0; i < m_dim; i++)
    {
        tmp.m_ptVector[i] -= vec.m_ptVector[i];
    }

    return tmp;
}

template <typename T>
CVector<T> &CVector<T>::operator-=(const CVector<T> &vec)
{
    if (m_dim != vec.m_dim)
        throw std::range_error("Dimensions must be the same");
    
    for(size_t i = 0; i < m_dim; i++)
    {
        m_ptVector[i] -= vec.m_ptVector[i];
    }

    return *this;
}

// scalar / dot product
template <typename T>
T CVector<T>::operator*(const CVector<T> &vec)
{
    if (m_dim != vec.m_dim)
        throw std::range_error("Dimensions must be the same");
    
    T product(0.0);

    for (size_t i = 0; i < m_dim; i++)
        product += m_ptVector[i] * vec.m_ptVector[i];

    return product;
}

// scaling
template <typename T>
CVector<T> &CVector<T>::operator*(const T &vec)
{
    for (size_t i = 0; i < m_dim; i++)
        m_ptVector[i] = vec * m_ptVector[i];

    return *this;
}

template <typename T>
CVector<T> CVector<T>::operator^(const CVector<T> &vec)
{
    if (m_dim != 3 || vec.m_dim != 3)
        throw std::range_error("Only defined for 3D vectors");
    
    CVector<T> tmp(*this);

    tmp.m_ptVector[0] = tmp.m_ptVector[2]*vec.m_ptVector[3] - tmp.vec.m_ptVector[3]*m_ptVector[2];
    tmp.m_ptVector[1] = tmp.m_ptVector[3]*vec.m_ptVector[1] - tmp.vec.m_ptVector[1]*m_ptVector[3];
    tmp.m_ptVector[2] = tmp.m_ptVector[1]*vec.m_ptVector[2] - tmp.vec.m_ptVector[2]*m_ptVector[1];

    return tmp;
}

template <typename T>
CVector<T> &CVector<T>::operator^=(const CVector<T> &vec)
{
    if (m_dim != 3 || vec.m_dim != 3)
        throw std::range_error("Only defined for 3D vectors");
    
    m_ptVector[0] = m_ptVector[2]*vec.m_ptVector[3] - vec.m_ptVector[3]*m_ptVector[2];
    m_ptVector[1] = m_ptVector[3]*vec.m_ptVector[1] - vec.m_ptVector[1]*m_ptVector[3];
    m_ptVector[2] = m_ptVector[1]*vec.m_ptVector[2] - vec.m_ptVector[2]*m_ptVector[1];

    return *this;
}

// ================================================
// [PUBLIC] FUNCTIONS
// ================================================

template <typename T>
void CVector<T>::show()
{
    std::cout << this->toString() << std::endl;
}

template <typename T>
std::string CVector<T>::toString()
{

    std::string str = "[";

    for (size_t i = 0; i < m_dim; i++)
        str += m_ptVector[i];

    str += "]";

    return str;
}

// ================================================
// [PRIVATE] FUNCTIONS
// ================================================

// ================================================
// [PUBLIC] MATHEMATICAL FUNCTIONS
// ================================================

template <typename T>
T CVector<T>::norm(EVectorNorms norm)
{

    T result(0.0);

    switch (norm)
    {
    case EVectorNorms::L1:
        for (size_t i = 0; i < m_dim; i++)
            result += abs(m_ptVector[i]);
        break;

    case EVectorNorms::L2:
        for (size_t i = 0; i < m_dim; i++)
            result += pow(m_ptVector[i], 2);
        result = sqrt(result);
        break;

    case EVectorNorms::MaxNorm:
        result = max(m_ptVector);
        break;
    }

    return result;
}

} // namespace Vector

} // namespace LinAlg
