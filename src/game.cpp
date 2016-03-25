#include "game.hpp"
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <ncurses.h>
Game::Game(){
}

Game::~Game(){

}
/*
void Game::mainloop(){
	Camera cam;
	clock_t begin_time = clock();
	float time_per_frame = 80000;
	Point rel = cam.get_ref();
	std::vector<Block> blocks;
	Block b1(Point(-5.5f*rel.x(), rel.y()/2,-350));
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			for(int k = 0; k < 10; ++k){
				//Block b(Point(i*get_size(), j*get_size(), ))
			}
		}
	}
	Point origin  = {-8*rel.x(),rel.y(),-1600};

	while(true){
		if(clock() - begin_time > time_per_frame){
			std::vector<Line> lines;
			b1.get_lines(lines);
			b1.rotate(Point(10,10,5));
			cam.add_lines(lines);
			cam.paint();
			begin_time = clock();
		}
	}
}
*/

void Game::mainloop(){
	// Init
	cbreak();
	initscr();
	clear();
	//noecho();
	Canvas c;
	Camera cam;
	Point campos = {0, 0, 0};
	cam.set_position(campos);
	clock_t begin_time = clock();
	float time_amount = 100000;
	//Loop
	Point pos(-60, -60, -400);
	Point pos2(60, -60, -400);
	Point pos3(0, 0, -400);
	

	//cam.add_pixel(pos);
	Block block(pos);
	Block block2(pos2);
	Block block3(pos3);


	while(true){
		//if(clock() - begin_time > time_amount){
		std::vector<Point> points;
		std::vector<Line> lines;
		Point move(0, 0, 0);
		Point rotation (0, 0, 0);
		Vector movevec(0,0,0);
		float speed = 10;
		char g = getch();
		Point camerarot = cam.get_rotation();
		Point camerapos = cam.get_position();
		if(g == 'd'){
			move = Point(0,0,0);
			Vector v = cam.right();
			move.add(v);
			move = move*speed;
		}
		if(g == 'a'){
			move = Point(0,0,0);
			Vector v = cam.left();
			move.add(v);
			move = move*speed;
		}		
		if(g == 'w'){
			move = Point(0,0,0);
			Vector v = cam.forward();
			move.add(v);
			move = move*speed;
		}
		if(g == 's'){
			move = Point(0,0,0);
			Vector v = cam.backwards();
			move.add(v);
			move = move*speed;
		}
		if(g == 'x'){
			rotation = Point(0,0,5);

		}
		if(g == 'c'){
			rotation = Point(0,0,-5);

		}
		if(g == 'q'){
			rotation = Point(0,5,0);
		}
		if(g == 'e'){
			rotation = Point(0,-5,0);
		}
		camerarot.add(rotation);
		camerapos.add(move);
		cam.set_rotation(camerarot);
		cam.set_position(camerapos);
		//block.rotate(rotation);
		//block.move(move);

		if(move.x() != 0 || move.z() != 0 || move.y() != 0 || rotation.x() != 0 || rotation.y() != 0 || rotation.z() != 0){
			//block.get_points(points);
			block.get_lines(lines);
			block2.get_lines(lines);
			block3.get_lines(lines);
			//Point i(0,0,-1);
			//std::cout << cam.is_behind(i) << std::endl;
			//cam.add_points(points);
			cam.add_lines(lines);
			cam.paint();
			Vector v = cam.forward();
			begin_time = clock();

		}
	}
	
}

/*
void Game::mainloop(){
	Canvas c;
	clock_t begin_time = clock();
	float time_amount = 100000;
// do something
	std::vector<Point> rectpoints;
	Point start = {0, 0, 0};
	Point end = {40, 0, 0};

	Line l1(start, end);

	start = {0, 0, 0};
	end = {0, 10, 0};
	
	Line l2(start, end);

	start = {10, 0, 0};
	end = {10, 10, 0};
	
	Line l3(start, end);

	start = {0, 40, 0};
	end = {40, 40, 0};
	
	Line l4(start, end);

	Point blockpoint(10,10,0);
	Rectangle rect(l1, l4);
	Block block(blockpoint);
	Point blockpoint2(0,0,0);
	Block block2(blockpoint2);
	block.get_points(rectpoints);
	//rect.rotate(45, 0, 0);
	//l1.rotate(10,0,0);
	//rect.get_points(rectpoints);
	//std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::vector<Point> points;
	for(int i = 0; i < 0; ++i){
		int x =0 + rand()% (c.get_screen_height());
		int y = 0 + rand()% (c.get_screen_width()/2);
		int z = rand()% 20;
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
			Point origin (30,30,0);
			//std::cout << origin << std::endl;
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
			//l1.rotate(10, 10, 10, &origin);
			std::vector<Point> linepoints;
			block.rotate(5,5,5);
			block.get_points(linepoints);
			block2.rotate(5,5,5,&origin);
			block2.get_points(linepoints);
			//rect.rotate(5, 20, 10);
			//rect.get_points(linepoints);
			//std::cout << linepoints[0].position()
			//l1.get_points(linepoints);
			//std::cout << "1: ("<<std::get<0>(linepoints[0].position()) << "," << std::get<1>(linepoints[0].position()) << "," << std::get<2>(linepoints[0].position()) << ")" << std::endl;
			//std::cout << "2: ("<<std::get<0>((linepoints.end()-1)->position()) << "," << std::get<1>((linepoints.end()-1)->position()) << "," << std::get<2>((linepoints.end()-1)->position()) << ")" << std::endl;
			//std::cout << " " << std::endl;
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
 */

