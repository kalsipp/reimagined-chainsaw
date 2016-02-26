#pragma once

#include <tuple>
#include "line.hpp"
#include "rectangle.hpp"

class Block{
public:
	Block(float x, float y, float z);
private:
	Rectangle m_north;
	Rectangle m_south;
	Rectangle m_east;
	Rectangle m_west;
	int m_size;
	int m_height;
};