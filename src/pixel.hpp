#pragma once
#include <string>
#include <iostream>
struct Pixel{
  std::string m_string;
  int m_value;
  Pixel();
  Pixel(int c);
  Pixel(std::string s);
  std::string get_str() const;
  int get_val() const;
};

