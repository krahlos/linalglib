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
  CVector(const CVector<T> &rhs);

  // Destructor
  ~CVector();

  // ================================================
  // [PUBLIC] OPERATORS
  // ================================================

  CVector<T> &operator=(const CVector<T> &rhs); // copy assignment operator

  T &operator()(size_t idx);
  T operator()(size_t idx) const;

  bool operator==(const CVector<T> &rhs) const;
  bool operator!=(const CVector<T> &rhs) const;

  CVector<T> operator+(const CVector<T> &rhs);
  CVector<T> &operator+=(const CVector<T> &rhs);

  CVector<T> operator-(const CVector<T> &rhs);
  CVector<T> &operator-=(const CVector<T> &rhs);

  T operator*(const CVector<T> &rhs);   // scalar / dot product

  CVector<T> &operator*(const T &rhs); // scaling

  CVector<T> operator^(const CVector<T> &rhs);   // cross product
  CVector<T> &operator^=(const CVector<T> &rhs); // cross product

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

  float angle_to(const CVector<T> &rhs);

  bool is_orthogonal_to(const CVector<T> &rhs);
};

} // namespace Vector

} // namespace LinAlg

#endif // __CVECTOR_H
