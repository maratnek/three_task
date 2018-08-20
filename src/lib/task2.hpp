// 2. Даны координаты x,y 3-х точек на плоскости,
// которые образуют треугольник.
// Для 4-ой точки с координатами x,y определить лежит ли она внутри треугольника.

#pragma once
// task2
#include <iostream>
using namespace std;

template <typename T>
struct point2D {
  T x, y;
  // point2D(T _x,, T _y) x(_x), y(_y){}
  friend ostream& operator<<(ostream& os, const point2D<T>& p) {
    os << "x: " << p.x << " y: " << p.y << std::endl;
    return os;
  }
};

using point = point2D<float>;

template <typename T>
T det(point2D<T> D, point2D<T> F, point2D<T> O)
{
  return (D.x - O.x)*(F.y - D.y) - (F.x - D.x)*(D.y - O.y);
}

template <typename T>
bool PointInTriangle(point2D<T> A, point2D<T> B, point2D<T> C, point2D<T> O)
{
    T a = det(A,B,O);
    T b = det(B,C,O);
    T c = det(C,A,O);
    // cout << "a: " << a << " b: " << b << " c: " << c << endl;
    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
      return true;
    return false;
}
