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
  CVector(size_t dim);

  /* TO DO
  // Constructor for special type Vector
  CVector(size_t dim, EVectorTypes type);
  */

  // Constructor to initialize the Vector directly
  CVector(T &ptVector, size_t dim);

  // Copy Constructor
  CVector(const CVector<T> &vec);

  // Destructor
  ~CVector();

  // ================================================
  // [PUBLIC] OPERATORS
  // ================================================

  CVector<T> &operator=(const CVector<T> &vec); // copy assignment operator

  T &operator()(size_t idx);
  T operator()(size_t idx) const;

  bool operator==(const CVector<T> &vec) const;
  bool operator!=(const CVector<T> &vec) const;

  CVector<T> operator+(const CVector<T> &vec);
  CVector<T> &operator+=(const CVector<T> &vec);

  CVector<T> operator-(const CVector<T> &vec);
  CVector<T> &operator-=(const CVector<T> &vec);

  T operator*(const CVector<T> &vec);   // scalar / dot product

  CVector<T> &operator*(const T &vec); // scaling

  CVector<T> operator^(const CVector<T> &vec);   // cross product
  CVector<T> &operator^=(const CVector<T> &vec); // cross product

  // ================================================
  // [PUBLIC] FUNCTIONS
  // ================================================

  size_t getDim() const { return m_dim; }

  EVectorTypes getType() const { return m_type; }

  void show();
  std::string toString();

  void set_value(size_t idx, T value);

  // ================================================
  // [PUBLIC] MATHEMATICAL FUNCTIONS
  // ================================================

  T norm(EVectorNorms norm);

  float angle_to(const CVector<T> &vec);

  bool is_orthogonal_to(const CVector<T> &vec);
};

} // namespace Vector

} // namespace LinAlg

#endif // __CVECTOR_H
