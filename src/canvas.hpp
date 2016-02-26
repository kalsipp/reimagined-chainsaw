#pragma once

#include <map>
#include <sys/ioctl.h>

#include "pixel.hpp"
class Canvas{

public:
	Canvas();
	void add_pixel(Pixel& pixel, int x, int y);
	void paint();
	void clear_grid();
	void clear_screen();
	void cursorpos(int x, int y);
	int get_screen_width();
	int get_screen_height();
private:
	int m_width = 0;
	int m_height = 0;
	int m_px = 0;
	int m_py = 0;
	std::map<std::pair<int,int>, Pixel> m_grid;

};
