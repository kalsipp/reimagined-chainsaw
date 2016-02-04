#include "canvas.hpp"


Canvas::Canvas(){
  
}

void Canvas::add_pixel(Pixel & pixel, int x, int y){
  std::pair<int, int> p = {x,y};
  m_grid[p] = pixel;
}

void Canvas::clear_grid(){
  m_grid.clear();
}


void Canvas::paint(){
  for(int y = 0; y < m_height; ++y){
    std::string s = "";
    for(int x = 0; x < m_width; ++x){
      std::pair<int, int> p = {x,y};
      if(m_grid.count(p) != 0){
        s+= m_grid[p].get_str();
      }
      else{
        s+= "  ";
      }
    }
    std::cout << s;
    std::cout.flush();
  }
 
}

