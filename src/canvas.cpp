#include "canvas.hpp"

Canvas::Canvas(){
  struct winsize w; //Get size of window
  ioctl(0, TIOCGWINSZ, &w);
  m_height = w.ws_row;
  m_width = w.ws_col*0.5f;
}
void Canvas::cursorpos(int px, int py){
  ++px; //escape is 1 base
  ++py;
  std::cout << "\033[" << py << ";" << px << "H";
} 

void Canvas::add_pixel(const Pixel & pixel, int x, int y){
	std::pair<int, int> p = {x,y};
	m_grid[p] = pixel;
}

void Canvas::clear_grid(){
	m_grid.clear();
}
void Canvas::clear_screen(){
	std::cout << "\033[2J";
}

void Canvas::paint(){
	clear_screen();
	for(int y = 0; y < m_height-2; ++y){
		std::string s = "";
		cursorpos(0,y);
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


int Canvas::get_screen_height(){
	return m_height;
}
int Canvas::get_screen_width(){
	return m_width;
}