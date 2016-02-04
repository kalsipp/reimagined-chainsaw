#include "pixel.hpp"
#include <string>

Pixel::Pixel(){
  m_string = "  \033[48m";
}

Pixel::Pixel(int c){
  m_value = c;
  m_string = "\033[48;5;" + std::to_string(c) + "m  " + "\033[0m";
}
Pixel::Pixel(std::string s){
  m_string = s + "\033[0m";
}
std::string Pixel::get_str()const{
  return m_string;
}
int Pixel::get_val()const{
  return m_value;
}
