#include "game.hpp"


int main(){
  Game * g = new Game();
  //g->autoloop();
  g->keyloop();
  delete g;
}

