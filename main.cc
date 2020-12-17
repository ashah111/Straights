#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
  int seed = 0;
  for (int i = 1; i < argc; i++){
    string s = (argv[i]);
    seed = stoi(argv[1]);
  }
  shared_ptr<Game> game = make_shared<Game>(seed);
  game->start();
}
