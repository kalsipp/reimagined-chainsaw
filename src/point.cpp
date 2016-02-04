#include "point.hpp"

Point::Point(int x, int y, int z){
 m_position = std::make_tuple(x, y, z);
 m_pixel = Pixel(0);
}
Point::Point(std::tuple<int, int, int> n){
  m_position = n;
  m_pixel = Pixel(0);
}
Point::~Point(){
}
std::tuple<int, int, int> & Point::position(){
  return m_position;
}

void Point::paint(Canvas & canvas){
  //int x = 0;
  //int y = 0;
  //canvas.add_pixel(m_pixel, x, y);
  std::cout << "(" << std::get<0>(m_position) << ", " << std::get<1>(m_position) << ", " << std::get<2>(m_position) << ")"<< std::endl;
}

void Point::set_position(int x, int y, int z){
    m_position = std::make_tuple(x, y, z);
}

void Point::set_pixel(Pixel & pixel){
  m_pixel = pixel;
}

Vector Point::operator-(Point & other){
  std::tuple<int, int, int> t(m_position);
  Vector p(t);
  p.subtract(other);
  return p;
  //p.subtract(other);
}

Point Point::operator+(Point & other){
  std::tuple<int, int, int> t(m_position);
  Point p(t);
  p.add(other);
  return p;
  //return
}
void Point::subtract(Point & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}

void Point::add(Point & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}


