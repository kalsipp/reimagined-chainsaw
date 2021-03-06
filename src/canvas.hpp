#pragma once
#include <map>
#include <sys/ioctl.h>

#include "pixel.hpp"

/*
Class for handling 2D output to terminal. Tranformation from 3d to 2d is done in camera.
*/

class Canvas{
public:
	Canvas();
	void add_pixel(const Pixel& pixel, int x, int y);
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