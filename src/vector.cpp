#include "vector.hpp"
#include <cassert>

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
}

Vector Vector::operator+(Vector & other){
  std::tuple<int, int, int> t(m_position);
  Vector p(t);
  p.add(other);
  return p;
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
int Vector::magnitude(){
  return std::get<0>(m_position)*std::get<0>(m_position)+std::get<1>(m_position)*std::get<1>(m_position) + std::get<2>(m_position)*std::get<2>(m_position);
}

void Vector::rotateXY(float degrees){
  int magn = magnitude();
  float radians = M_PI*degrees/180;
  int old_x = std::get<0>(m_position);
  int old_y = std::get<1>(m_position);
  std::get<0>(m_position) = round(old_x*cos(radians)) - round(old_y*sin(radians));
  std::get<1>(m_position) = round(old_x*sin(radians)) + round(old_y*cos(radians));

}

void Vector::rotateXZ(float degrees){
  float radians = M_PI*degrees/180;
  int old_x = std::get<0>(m_position);
  int old_z = std::get<2>(m_position);
  std::get<0>(m_position) = round(old_x*cos(radians)) + round(old_z*sin(radians));
  std::get<2>(m_position) = -round(old_x*sin(radians)) + round(old_z*cos(radians));
}
void Vector::rotateYZ(float degrees){
  float radians = M_PI*degrees/180;
  int old_y = std::get<1>(m_position);
  int old_z = std::get<2>(m_position);
  std::get<1>(m_position) = round(old_y*cos(radians)) + round(old_z*sin(radians));
  std::get<2>(m_position) = -round(old_y*sin(radians)) + round(old_z*cos(radians));
}