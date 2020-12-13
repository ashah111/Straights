#include <iostream>
#include <vector>
#include <string>
#include "humanPlayer.h"

class Player;

using namespace std;

HumanPlayer::HumanPlayer() {
  setScore(0);
}

string HumanPlayer::playerType(){
  return "human";
}
