#include <iostream>
#include <vector>
#include <string>
#include "computerPlayer.h"

class Player;

using namespace std;

ComputerPlayer::ComputerPlayer() {
  setScore(0);
}

ComputerPlayer::ComputerPlayer( Player& humanPlayer ){
  setHand(humanPlayer.getHand());
  setDiscardPile(humanPlayer.getDiscardPile());
  setScore(humanPlayer.getScore());
}

PLAYER_TYPE ComputerPlayer::playerType() const{
  return COMPUTER;
}

void ComputerPlayer::play() {
  if (getLegalPlays().size() == 0){
    discardCard(0);
  }else {
    int idx = findCard(getLegalPlays()[0],getHand());
    playCard(idx);
  }
}
