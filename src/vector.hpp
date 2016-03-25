#pragma once
#include <tuple>
#include <math.h>
#include "point.hpp"
class Point;
class Vector{
public:
  Vector(float x = 0, float y = 0, float z = 0);
  Vector(std::tuple<float, float, float>);
  ~Vector();
  std::tuple<float, float, float> & position();
  void set_position(float x = 0, float y = 0, float z = 0);
  float magnitude();
  float & x();
  float & y();
  float & z();
  void scale(float x = 1, float y = 1, float z = 1);
  void subtract(Vector & other);
  void subtract(Point & other);
  void add(Vector & other);
  void rotateXY(float degrees);
  void rotateXZ(float degrees);
  void rotateYZ(float degrees);
  Vector cross(Vector other);
  void normalize();
  Vector operator-(Vector & other);
  Vector operator+(Vector & other);
  Vector operator*(double num);
  Vector operator*(Vector other);
  friend std::ostream & operator<<(std::ostream & stream, Vector & p);
  
private:
  std::tuple<float, float, float>  m_position;

};
