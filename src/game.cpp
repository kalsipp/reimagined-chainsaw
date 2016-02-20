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
	//std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

	std::vector<Point> points;
	for(int i = 0; i < 1000; ++i){
		int x = rand()% c.get_screen_height()*2;
		int y = rand()% c.get_screen_width();
		int z = rand()% 10;
		Point p(x,y,z);
		Pixel pix (100);
		p.set_pixel(pix);
		points.push_back(p);
	}
	for(int i = 0; i < points.size(); ++i){
		points[i].paint(c);
	}
	c.paint();
	while(true){
		if(clock() - begin_time > time_amount){
            //create the space's origin as a point
			Point origin (20,20,0);
			Vector tempVector;
			for (int x = 0; x < points.size(); x++)
			{
                //store the current vector address for the point, and set the point
				tempVector = points[x]-(origin);
                //reset the point so that the scaled vector can be added
				points[x].set_position(origin);
                //scale the vector and set the point to its new, scaled location
				//tempVector.rotateXY(15);
				tempVector.rotateXZ(15);
				tempVector.rotateYZ(15);
				points[x].add(tempVector);
			}
			c.clear_grid();
			for(int i = 0; i < points.size(); ++i){
				points[i].paint(c);
			}
			c.paint();
			begin_time = clock();
		}
            //redrawScreen();
	}
}
