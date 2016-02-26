#include "game.hpp"
#include <vector>
#include <stdlib.h>
#include <ctime>
Game::Game(){
}

Game::~Game(){

}

void Game::mainloop(){
	Canvas c;
	clock_t begin_time = clock();
	float time_amount = 100000;
// do something
	std::vector<Point> rectpoints;
	Point start = {10, 0, 0};
	Point end = {20, 5, 5};

	Line l1(start, end);

	start = {0, 0, 0};
	end = {0, 10, 0};
	
	Line l2(start, end);

	start = {10, 0, 0};
	end = {10, 10, 0};
	
	Line l3(start, end);

	start = {0, 10, 0};
	end = {10, 10, 0};
	
	Line l4(start, end);


	Rectangle rect(l1, l2, l3, l4);
	rect.rotate(45, 0, 0);
	//l1.rotate(10,0,0);
	//rect.get_points(rectpoints);
	//std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::vector<Point> points;
	for(int i = 0; i < 10000; ++i){
		int x =0 + rand()% (c.get_screen_height());
		int y = 0 + rand()% (c.get_screen_width()/2);
		int z = rand()% 1;
		Point p(x,y,z);
		Pixel pix (100);
		p.set_pixel(pix);
		points.push_back(p);
	}
	for(int i = 0; i < points.size(); ++i){
		points[i].paint(c);
	}
	for(auto i = rectpoints.begin(); i != rectpoints.end(); ++i){
		(*i).paint(c);
	}
	c.paint();
	
	while(true){
		if(clock() - begin_time > time_amount){
            //create the space's origin as a point
			Point origin (15,15,0);
			Vector tempVector;
			for (int x = 0; x < points.size(); x++)
			{
                //store the current vector address for the point, and set the point
				tempVector = points[x]-(origin);
                //reset the point so that the scaled vector can be added
				points[x].set_position(origin);
                //scale the vector and set the point to its new, scaled location
				tempVector.rotateXY(5);
				tempVector.rotateXZ(5);
				tempVector.rotateYZ(15);
				points[x].add(tempVector);
			}
			l1.rotate(10, 10, 10, &origin);
			std::vector<Point> linepoints;
			//rect.rotate(0, 10, 0, &origin);
			//rect.get_points(linepoints);
			//std::cout << linepoints[0].position()
			l1.get_points(linepoints);
			std::cout << "1: ("<<std::get<0>(linepoints[0].position()) << "," << std::get<1>(linepoints[0].position()) << "," << std::get<2>(linepoints[0].position()) << ")" << std::endl;
			std::cout << "2: ("<<std::get<0>((linepoints.end()-1)->position()) << "," << std::get<1>((linepoints.end()-1)->position()) << "," << std::get<2>((linepoints.end()-1)->position()) << ")" << std::endl;
			std::cout << " " << std::endl;
			c.clear_grid();
			for(auto i = linepoints.begin(); i != linepoints.end(); ++i){
				(*i).paint(c);
			}
			for(int i = 0; i < points.size(); ++i){
				points[i].paint(c);
			}
			c.paint();
			begin_time = clock();
		}
            //redrawScreen();
	}

}
