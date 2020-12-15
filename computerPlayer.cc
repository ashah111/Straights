#include <iostream>
#include <vector>
#include <string>
#include "computerPlayer.h"

class Player;

using namespace std;

ComputerPlayer::ComputerPlayer() {
  setScore(0);
}

ComputerPlayer::ComputerPlayer(shared_ptr<Player> humanPlayer ){
  setHand(move(humanPlayer->getHand()));
  setDiscardPile(humanPlayer->getDiscardPile());
  setScore(humanPlayer->getScore());
  setScoreGained(humanPlayer->getScoreGained());
}

PLAYER_TYPE ComputerPlayer::playerType() const{
  return COMPUTER;
}

void ComputerPlayer::play() {
  if (getLegalPlays().size() == 0){
    cout << "discards "<< getHand()[0]->toString() << endl;
    discardCard(0);
  }else {
    int idx = findCard(getLegalPlays()[0],getHand());
    cout << "plays "<< getHand()[idx]->toString() << endl;
    playCard(idx);
  }
}
