#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "humanPlayer.h"
#include "card.h"

class Player;

using namespace std;

HumanPlayer::HumanPlayer() {
  setScore(0);
}

PLAYER_TYPE HumanPlayer::playerType() const{
  return HUMAN;
}

void HumanPlayer::play(string input){
  int idx;
  shared_ptr<Card> card;
  if (input.length() == 2) card = make_shared<Card>(input.substr(0,1),input.substr(1,1));
  else throw InvalidValueException();

  idx = findCard(card,getLegalPlays());
  if (idx < 0) throw InvalidValueException();

  idx = findCard(card,getHand());
  playCard(idx);
}

void HumanPlayer::discard(string input){
  int idx;
  shared_ptr<Card> card;

  if (input.length() == 2) card = make_shared<Card>(input.substr(0,1),input.substr(1,1));
  else throw InvalidValueException();

  idx = findCard(card,getHand());
  if (idx < 0) throw InvalidValueException();

  discardCard(idx);
}
