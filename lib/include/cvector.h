#ifndef __CVECTOR_H
#define __CVECTOR_H

#include <math.h>
#include <iostream>
#include <string>

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

enum EVectorNorms
{
  L1 = 1,
  L2,
  // Lp, Todo: Find good solution for p-Norm
  MaxNorm
};

template <typename T>
class CVector
{
private:
  // ================================================
  // [PRIVATE] FUNCTIONS
  // ================================================

  // ================================================
  // [PRIVATE] MEMBER
  // ================================================

  T *m_ptVector;
  size_t m_dim;

  EVectorTypes m_type;

public:
  // ================================================
  // [PUBLIC] CONSTRUCTORS AND DESTRUCTORS
  // ================================================

  // Default Constructor
  CVector(size_t dim) : m_dim(dim)
  {
      m_ptVector = malloc(dim * sizeof(T));
      m_type = EVectorTypes::None;
  }

  /* TO DO
  // Constructor for special type Vector
  CVector(size_t dim, EVectorTypes type);
  */

  // Constructor to initialize the Vector directly
  CVector(T &ptVector, size_t dim) : m_dim(dim)
  {
      m_ptVector = ptVector;
  }

  // Copy Constructor
  CVector(const CVector<T> &vec);

  // Destructor
  ~CVector();

  // ================================================
  // [PUBLIC] OPERATORS
  // ================================================

  // copy assignment operator
  CVector<T> &operator=(const CVector<T> &vec)
  {
      if(this != &vec)
      {
          delete [] m_ptVector;
          copy(vec);
      }

      return *this;
  }

  T &operator()(size_t idx)
  {
      if (idx > m_dim)
          throw std::out_of_range("Index out of range.");

      return m_ptVector[idx];
  }

  T operator()(size_t idx) const
  {
      if (idx > m_dim)
          throw std::out_of_range("Index out of range.");

      return m_ptVector[idx];
  }

  bool operator==(const CVector<T> &vec) const
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

  bool operator!=(const CVector<T> &vec) const
  {
      return !((*this) == vec);
  }

  CVector<T> operator+(const CVector<T> &vec)
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

  CVector<T> &operator+=(const CVector<T> &vec)
  {
      if (m_dim != vec.m_dim)
          throw std::range_error("Dimensions must be the same");
      
      for(size_t i = 0; i < m_dim; i++)
      {
          m_ptVector[i] += vec.m_ptVector[i];
      }

      return *this;
  }

  CVector<T> operator-(const CVector<T> &vec)
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

  CVector<T> &operator-=(const CVector<T> &vec)
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
  T operator*(const CVector<T> &vec)
  {
      if (m_dim != vec.m_dim)
          throw std::range_error("Dimensions must be the same");
      
      T product(0.0);

      for (size_t i = 0; i < m_dim; i++)
          product += m_ptVector[i] * vec.m_ptVector[i];

      return product;
  }

  // scaling
  CVector<T> &operator*(const T &vec)
  {
      for (size_t i = 0; i < m_dim; i++)
          m_ptVector[i] = vec * m_ptVector[i];

      return *this;
  }

  CVector<T> operator^(const CVector<T> &vec)
  {
      if (m_dim != 3 || vec.m_dim != 3)
          throw std::range_error("Only defined for 3D vectors");
      
      CVector<T> tmp(*this);

      tmp.m_ptVector[0] = tmp.m_ptVector[2]*vec.m_ptVector[3] - tmp.vec.m_ptVector[3]*m_ptVector[2];
      tmp.m_ptVector[1] = tmp.m_ptVector[3]*vec.m_ptVector[1] - tmp.vec.m_ptVector[1]*m_ptVector[3];
      tmp.m_ptVector[2] = tmp.m_ptVector[1]*vec.m_ptVector[2] - tmp.vec.m_ptVector[2]*m_ptVector[1];

      return tmp;
  }

  CVector<T> &operator^=(const CVector<T> &vec)
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

  size_t getDim() const { return m_dim; }

  EVectorTypes getType() const { return m_type; }

  void show()
  {
    std::cout << this->toString() << std::endl;
  }

  std::string toString()
  {
    std::string str = "[";

    for (size_t i = 0; i < m_dim; i++)
        str += m_ptVector[i];

    str += "]";

    return str;
  }

  void set_value(size_t idx, T value);

  // ================================================
  // [PUBLIC] MATHEMATICAL FUNCTIONS
  // ================================================

  T norm(EVectorNorms norm)
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

  float angle_to(const CVector<T> &vec);

  bool is_orthogonal_to(const CVector<T> &vec);
};

} // namespace Vector

} // namespace LinAlg

#endif // __CVECTOR_H
