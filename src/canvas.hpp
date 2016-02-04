#pragma once

#include <map>
#include "pixel.hpp"

class Canvas{

public:
  Canvas();
  void add_pixel(Pixel& pixel, int x, int y);
  void paint();
  void clear_grid();
private:
  int m_width = 0;
  int m_height = 0;
  int m_px = 0;
  int m_py = 0;
  std::map<std::pair<int,int>, Pixel> m_grid;

};
