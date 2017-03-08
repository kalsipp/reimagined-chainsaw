#include "game.hpp"

Game::Game(){

}
Game::~Game(){

}

void Game::keyloop(){
	cbreak();
	initscr();
	clear();
	Camera camera(Vector(0,0,0), Vector(0,0,0));
	Vector pos1(0,0,100);
	Vector pos2;
	pos2.set(pos1);
	pos2.add(0, -20, 0);
	Block block(pos2);
	pos2.set(pos1);
	pos2.add(block.get_size().x()*2, 0, 0);
	Block block2(pos2);
	pos2.set(pos1);
	pos2.add(-block.get_size().x()*2, 0, 0);
	Block block3(pos2);
	std::vector<Block> blocks;
	blocks.push_back(block);
	blocks.push_back(block2);
	blocks.push_back(block3);

	//Line line(block.get_middle(), block2.get_middle(), 50);

	float speed = 5;
	while(1){
		std::vector<Line> lines;
		Vector rotation(0,0,0);
		Vector movement(0,0,0);

		char g = getch();
		if(g == 'd'){
			movement = camera.right();
			movement.mult(speed);	
			movement.z() = -movement.z();
			movement.y() = 0;

		}
		if(g == 'a'){
			movement = camera.right();
			movement.mult(-1);
			movement.mult(speed);
			movement.z() = -movement.z();
			movement.y() = 0;

		}		
		if(g == 'w'){
			movement = camera.forward();
			movement.mult(speed);	
			movement.y() = 0;

		}
		if(g == 's'){
			movement = camera.forward();
			movement.mult(-1);
			movement.mult(speed);
			movement.y() = 0;
		}
		if(g == 'x'){
			rotation = Vector(speed,0,0);
		}
		if(g == 'c'){
			rotation = Vector(-speed,0,0);

		}
		if(g == 'q'){
			rotation = Vector(0,speed,0);
		}
		if(g == 'e'){
			rotation = Vector(0,-speed,0);
		}
		camera.move(movement);
		camera.rotate(rotation);
		//if(rotation.x() != 0 || rotation.y() != 0 || rotation.z() != 0){
		//	block.rotate_around(rotation, camera.get_position());
		//}
		for(auto i = blocks.begin(); i != blocks.end(); ++i){
			i->rotate(Vector(5,5,5));

			i->rotate_around(Vector(5,6,7), Vector(0,0,0));
			i->get_lines(lines);
		}
		//lines.push_back(line);
		//block.get_lines(lines);
		camera.add_lines(lines);
		camera.paint();
		std::cout << camera.is_in_front(block.get_middle()) << std::endl;


	}
}

void Game::autoloop(){
	std::default_random_engine generator;
  	//std::uniform_int_distribution<int> distribution(0,100);
  	std::uniform_int_distribution<int> distribution(0,8);
	std::vector<Block> blocks;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3;++j){
			int x = distribution(generator);
			int y = distribution(generator);
			int z = distribution(generator);
			Block b(Vector(x*10,y*10,z*10));
			blocks.push_back(b);

		}
		
	}


	Camera camera(Vector(10,10,-20), Vector(0,0,0));
	std::vector<Vector> rots;
	for (int i = 0; i < blocks.size(); ++i){
		int x = distribution(generator);
		int y = distribution(generator);
		int z = distribution(generator);
		rots.push_back(Vector(x,y,z));
		std::cout << (rots[i]) << std::endl;

	}
	/*
	Vector pos1(0,0,100);
	Vector pos2;
	pos2.set(pos1);
	pos2.add(0, -20, 0);
	Block block(pos2);
	pos2.set(pos1);
	pos2.add(block.get_size().x()*3, 0, 0);
	Block block2(pos2);
	pos2.set(pos1);
	pos2.add(-block.get_size().x()*3, 0, 0);
	Block block3(pos2);

	Block block4(pos2);
	blocks.push_back(block);
	blocks.push_back(block2);
	blocks.push_back(block3);
	blocks.push_back(block4);
	*/
	clock_t begin_time = clock();
	float time_amount = 30000;
	std::cout << "forward " << camera.forward() << std::endl;
	while(1){
		if(clock() - begin_time > time_amount){
			camera.get_rotation() = Vector(0,0,0);
			std::vector<Line> lines;
			std::vector<Point> points;
			//blocks[0].rotate_around(Vector(3,4,1), Vector(10, -20, 50));
			//blocks[1].rotate_around(Vector(1,2,5), Vector(10, -20, 10));
			//blocks[2].rotate_around(Vector(5,1,7), Vector(10, -20, -20));
			//blocks[3].rotate_around(Vector(1,2,1), Vector(10, 0, 0));
			for(int i = 0; i < blocks.size(); ++i){
				blocks[i].rotate(Vector(1,2,3));
				blocks[i].rotate_around(rots[i], rots[i]);
				blocks[i].get_lines(lines);
			}
			//std::cout << camera.is_in_front(pos1) << std::endl;
			camera.add_lines(lines);
			camera.paint();

			begin_time = clock();

		}
	}
}