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

string ComputerPlayer::playerType(){
  return "computer";
}

void ComputerPlayer::play(){
  // //Get legal plays
  // vector<shared_ptr<Card>> legalPlays = legalPlays();
  // //if legalPlays >= 1 - play card
  // if (legalPlays.size() > 0){
  //
  // }else{
  //   discardCard
  // }

}
