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

  T *m_ptData;
  size_t m_dim;

  EVectorTypes m_type;

public:
  // ================================================
  // [PUBLIC] CONSTRUCTORS AND DESTRUCTORS
  // ================================================

  // Default Constructor
  CVector(size_t dim) : m_dim(dim)
  {
      //m_ptData = (T*) malloc(m_dim * sizeof(T));
      m_ptData = new T[m_dim];
      for (size_t i = 0; i < m_dim; i++)
      {
          m_ptData[i] = T(0.0);
      }
      m_type = EVectorTypes::None;
  }

  /* TO DO
  // Constructor for special type Vector
  CVector(size_t dim, EVectorTypes type);
  */

  // Constructor to initialize the Vector directly
  CVector(T &ptVector, size_t dim) : m_dim(dim)
  {
      m_ptData = ptVector;
  }

  // Copy Constructor
  CVector(const CVector<T> &vec)
  {
      m_dim = vec.m_dim;
      m_ptData = (T*) malloc(m_dim * sizeof(T));
      for (size_t i = 0; i < m_dim; i++)
      {
          m_ptData[i] = vec.m_ptData[i];
      }
      m_type = vec.m_type;
  }

  // Destructor
  virtual ~CVector()
  {
    delete [] m_ptData;
  }

  // ================================================
  // [PUBLIC] OPERATORS
  // ================================================

  // copy assignment operator
  CVector<T> &operator=(const CVector<T> &vec)
  {
      if(this != &vec)
      {
          delete [] m_ptData;
          copy(vec);
      }

      return *this;
  }

  T &operator()(size_t idx)
  {
      if (idx > m_dim)
          throw std::out_of_range("Index out of range.");

      return m_ptData[idx];
  }

  T operator()(size_t idx) const
  {
      if (idx > m_dim)
          throw std::out_of_range("Index out of range.");

      return m_ptData[idx];
  }

  bool operator==(const CVector<T> &vec) const
  {
      if ((m_dim != vec.m_dim))
      {
          return false;
      }

      for (size_t i = 0; i < m_dim; i++)
      {
          if (m_ptData[i] != vec.m_ptData[i])
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
          tmp.m_ptData[i] += vec.m_ptData[i];
      }

      return tmp;
  }

  CVector<T> &operator+=(const CVector<T> &vec)
  {
      if (m_dim != vec.m_dim)
          throw std::range_error("Dimensions must be the same");
      
      for(size_t i = 0; i < m_dim; i++)
      {
          m_ptData[i] += vec.m_ptData[i];
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
          tmp.m_ptData[i] -= vec.m_ptData[i];
      }

      return tmp;
  }

  CVector<T> &operator-=(const CVector<T> &vec)
  {
      if (m_dim != vec.m_dim)
          throw std::range_error("Dimensions must be the same");
      
      for(size_t i = 0; i < m_dim; i++)
      {
          m_ptData[i] -= vec.m_ptData[i];
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
          product += m_ptData[i] * vec.m_ptData[i];

      return product;
  }

  // scaling
  CVector<T> &operator*(const T &vec)
  {
      for (size_t i = 0; i < m_dim; i++)
          m_ptData[i] = vec * m_ptData[i];

      return *this;
  }

  CVector<T> operator^(const CVector<T> &vec)
  {
      if (m_dim != 3 || vec.m_dim != 3)
          throw std::range_error("Only defined for 3D vectors");
      
      CVector<T> tmp(*this);

      tmp.m_ptData[0] = tmp.m_ptData[2]*vec.m_ptData[3] - tmp.vec.m_ptData[3]*m_ptData[2];
      tmp.m_ptData[1] = tmp.m_ptData[3]*vec.m_ptData[1] - tmp.vec.m_ptData[1]*m_ptData[3];
      tmp.m_ptData[2] = tmp.m_ptData[1]*vec.m_ptData[2] - tmp.vec.m_ptData[2]*m_ptData[1];

      return tmp;
  }

  CVector<T> &operator^=(const CVector<T> &vec)
  {
      if (m_dim != 3 || vec.m_dim != 3)
          throw std::range_error("Only defined for 3D vectors");
      
      m_ptData[0] = m_ptData[2]*vec.m_ptData[3] - vec.m_ptData[3]*m_ptData[2];
      m_ptData[1] = m_ptData[3]*vec.m_ptData[1] - vec.m_ptData[1]*m_ptData[3];
      m_ptData[2] = m_ptData[1]*vec.m_ptData[2] - vec.m_ptData[2]*m_ptData[1];

      return *this;
  }

  // ================================================
  // [PUBLIC] FUNCTIONS
  // ================================================

  // GETTER
  // ------------------------------------------------

  size_t get_dim () const
  { 
      return m_dim; 
  }

  EVectorTypes get_type () const
  { 
      return m_type; 
  }

  T* get_data () const
  { 
      return m_ptData; 
  }

  T get_data (size_t idx) const
  { 
    if (idx < 0 ||  idx > m_dim)
      throw std::out_of_range("Index out of range.");
    
    return m_ptData[idx]; 
  }

  // SETTER
  // ------------------------------------------------

  void set_data(size_t idx, T value) 
  { 
    if (idx < 0 ||  idx > m_dim)
      throw std::out_of_range("Index out of range.");

    m_ptData[idx] = value;
  }

  // MISCELLANEOUS
  // ------------------------------------------------

  void show()
  {
    std::cout << this->to_string() << std::endl;
  }

  std::string to_string()
  {
    std::string str = "[";

    for (size_t i = 0; i < m_dim; i++){
        str += std::to_string(m_ptData[i]);
        if (i < m_dim - 1)
            str += " ";
    }


    str += "]";

    return str;
  }

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
            result += abs(m_ptData[i]);
        break;

    case EVectorNorms::L2:
        for (size_t i = 0; i < m_dim; i++)
            result += pow(m_ptData[i], 2);
        result = sqrt(result);
        break;

    case EVectorNorms::MaxNorm:
        result = max(m_ptData);
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
