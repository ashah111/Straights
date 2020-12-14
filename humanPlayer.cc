#include <iostream>
#include <vector>
#include <string>
#include "humanPlayer.h"

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
  if (input.length() == 2){
    card->setRank(Rank(stoi(input.substr(0,1))));
    card->setSuit(Suit(stoi(input.substr(1,1))));
  }
  else if (input.length() == 3){
    card->setRank(Rank(stoi(input.substr(0,2))));
    card->setSuit(Suit(stoi(input.substr(2,1))));
  } else throw InvalidValueException();

  cout << "break 1" << endl;
  idx = findCard(card,getLegalPlays());
  cout << "break 2" << endl;
  if (idx < 0) throw InvalidValueException();

  idx = findCard(card,getHand());
  cout << "break 3" << endl;
  playCard(idx);
  cout << "break 4" << endl;
}

void HumanPlayer::discard(string input){
  int idx;
  shared_ptr<Card> card;
  if (input.length() == 2){
    card->setRank(Rank(stoi(input.substr(0,1))));
    card->setSuit(Suit(stoi(input.substr(1,1))));
  }
  else if (input.length() == 3){
    card->setRank(Rank(stoi(input.substr(0,2))));
    card->setSuit(Suit(stoi(input.substr(2,1))));
  } else throw InvalidValueException();


  idx = findCard(card,getHand());
  if (idx < 0) throw InvalidValueException();

  discardCard(idx);
}
