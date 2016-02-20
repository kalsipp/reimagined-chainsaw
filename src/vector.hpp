#pragma once
#include <tuple>
#include <math.h>
#include "point.hpp"
class Point;
class Vector{
public:
  Vector(int x = 0, int y = 0, int z = 0);
  Vector(std::tuple<int, int, int>);
  ~Vector();
  std::tuple<int, int, int> & position();
  void set_position(int x = 0, int y = 0, int z = 0);
  int magnitude();
  void subtract(Vector & other);
  void subtract(Point & other);
  void add(Vector & other);
  void rotateXY(float degrees);
  void rotateXZ(float degrees);
  void rotateYZ(float degrees);
  Vector operator-(Vector & other);
  Vector operator+(Vector & other);
  
private:
  std::tuple<int, int, int>  m_position;

};
