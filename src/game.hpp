#pragma once
#include <vector>
#include <ncurses.h>
#include "vector.hpp"
#include "point.hpp"
#include "line.hpp"
#include "block.hpp"
#include "camera.hpp"
class Game{
public:
  Game();
  ~Game();
  void autoloop();
  void keyloop();
  
};


