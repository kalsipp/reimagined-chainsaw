#include "game.hpp"

int main(){
  Game * g = new Game();
  g->mainloop();
  delete g;
}
