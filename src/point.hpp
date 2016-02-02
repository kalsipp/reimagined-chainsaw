#pragma once
#include <tuple>
#include "vector.hpp"
class Vector;
class Point{
public:
  Point(int x = 0, int y = 0, int z = 0);
  Point(std::tuple<int, int, int>);
  ~Point();
  std::tuple<int, int, int> & position();
  void set_position(int x = 0, int y = 0, int z = 0);
  void subtract(Point & other);
  void subtract(Vector & other);
  void add(Point & other);
  void add(Vector & other);
  Vector operator-(Point & other);
  Point operator+(Point & other);
private:
  std::tuple<int, int, int>  m_position;
};
