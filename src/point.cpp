#include "point.hpp"

Point::Point(float x, float y, float z){
 m_position = std::make_tuple(x, y, z);
 m_pixel = Pixel(100);
}
Point::Point(std::tuple<float, float, float> n){
  m_position = n;
  m_pixel = Pixel(100);
}
Point::Point(std::initializer_list<float> l){
  std::vector<float> v;
  v.insert(v.end(), l.begin(), l.end()); 
  m_position = std::make_tuple(v[0], v[1], v[3]);
}
std::tuple<float, float, float> & Point::position(){
  return m_position;
}

void Point::paint(Canvas & canvas){
  int x = round(std::get<0>(m_position));
  int y = round(std::get<1>(m_position));
  canvas.add_pixel(m_pixel, x, y);
}

void Point::set_position(float x, float y, float z){
  m_position = std::make_tuple(x, y, z);
}
void Point::set_position(Point & other){
  m_position = other.position();
}

void Point::set_pixel(Pixel & pixel){
  m_pixel = pixel;
}

Point Point::operator*(double num){
 std::tuple<float, float, float> t = std::make_tuple(std::get<0>(m_position)*num,
  std::get<1>(m_position)*num, 
  std::get<2>(m_position)*num);
 Point p(t);
 return p;
}

Vector Point::operator-(Point & other){
  std::tuple<float, float, float> t(m_position);
  Vector p(t);
  p.subtract(other);
  return p;
  //p.subtract(other);
}

Point Point::operator+(Point & other){
  std::tuple<float, float, float> t(m_position);
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

Point Point::sub(Point & other){
  Point p(m_position);
  p.subtract(other);
  return p;
}

void Point::add(Point & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}

void Point::add(Vector & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}


