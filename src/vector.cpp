#include "vector.hpp"


Vector::Vector(int x, int y, int z){
 m_position = std::make_tuple(x, y, z);
}
Vector::Vector(std::tuple<int, int, int> n){
  m_position = n;
}
Vector::~Vector(){
}
std::tuple<int, int, int> & Vector::position(){
  return m_position;
}

Vector Vector::operator-(Vector & other){
  std::tuple<int, int, int> t(m_position);
  Vector p(t);
  p.subtract(other);
  return p;
  //p.subtract(other);
}

Vector Vector::operator+(Vector & other){
  std::tuple<int, int, int> t(m_position);
  Vector p(t);
  p.add(other);
  return p;
  //return
}
void Vector::subtract(Vector & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}

void Vector::subtract(Point & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}

void Vector::add(Vector & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}


void Vector::set_position(int x, int y, int z){
    m_position = std::make_tuple(x, y, z);
}

