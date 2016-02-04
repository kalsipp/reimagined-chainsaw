#pragma once
#include <tuple>
#include "vector.hpp"
#include "pixel.hpp"
#include "canvas.hpp"
class Vector;
class Point{
public:
  Point(int x = 0, int y = 0, int z = 0);
  Point(std::tuple<int, int, int>);
  ~Point();
  
  void paint(Canvas & canvas);
  
  std::tuple<int, int, int> & position();
  
  void set_position(int x = 0, int y = 0, int z = 0);
  void set_pixel(Pixel & pixel);
  
  void subtract(Point & other);
  void subtract(Vector & other);
  
  void add(Point & other);
  void add(Vector & other);
  
  Vector operator-(Point & other);
  Point operator+(Point & other);
  

private:
  Pixel m_pixel;
  std::tuple<int, int, int>  m_position;
};
