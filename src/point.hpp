#pragma once
#include <tuple>
#include <math.h>
#include <initializer_list>
#include <vector>

#include "vector.hpp"
#include "pixel.hpp"
#include "canvas.hpp"
class Vector;
class Point{
public:
  Point(float x = 0, float y = 0, float z = 0);
  Point(std::tuple<float, float, float>);
  Point(std::initializer_list<float> l);
  void paint(Canvas & canvas);
  
  const std::tuple<float, float, float> & position()const;
  std::tuple<float, float, float> & position();
  void set_position(float x = 0, float y = 0, float z = 0);
  void set_position(Point & other);
  void set_position(std::tuple<float, float, float>);
  void set_pixel(Pixel & pixel);
  float & x();
  float & y();
  float & z();
  void subtract(Point & other);
  void subtract(Vector & other);
  Point sub(Point & other);
  void add(Point & other);
  void add(Vector & other);
  Point operator-();
  Vector operator-(Point other);
  Point operator*(Point);
  bool operator < (const Point& str)const;
  Point operator+(Point other);
  Point operator*(double other);

  friend std::ostream & operator<<(std::ostream & stream, Point & p);

private:
  Pixel m_pixel;
  std::tuple<float, float, float>  m_position;
};
