#include <cmath>
#include <vector>
#include <algorithm>
#include "point.hpp"
#include "line.hpp"
#include "canvas.hpp"
class Camera{
public:
	Camera();
	Camera(Point & pos, Point & rot);
	Point & get_rotation();
	Point & get_position();
	Point & get_max_view();
	Point & get_min_view();
	Point get_ref();
	Vector forward();
	Vector backwards();
	Vector right();
	Vector left();
	Vector up();
	Vector down();
	void set_rotation(Point &);
	void set_position(Point &);
	void add_points(std::vector<Point>);
	void add_lines(std::vector<Line> );
	void add_pixel(Point);
	bool is_behind(Point v1);
	void paint();
private:
	Point m_position;
	Point m_max_view = Point(10, 10, 10);
	Point m_min_view = Point(-10, -10, 0);
	Point m_rotation = Point(0,0,0);
	Canvas m_canvas; 
};