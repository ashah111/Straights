#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "player.h"
#include "card.h"

using namespace std;

Player::Player():score{0}, scoreGained{0}{}

int Player::setHand(vector<shared_ptr<Card>> newHand){
  hand = newHand;
  auto found = find_if(newHand.begin(), newHand.end(), [&](shared_ptr<Card>& p){
    return (p->getRank() == 7 && p->getSuit() == SPADES);
  });
  if (found != newHand.end()) return 1;
  return -1;
}

void Player::setDiscardPile(vector<shared_ptr<Card>> newDiscard){
  discardPile = newDiscard;
}

void Player::setScore(int n){
  score = n;
}

void Player::setScoreGained(int n){
  scoreGained = n;
}

vector<shared_ptr<Card>> Player::getHand(){
  return hand;
}

vector<shared_ptr<Card>> Player::getDiscardPile(){
  return discardPile;
}

vector<shared_ptr<Card>> Player::getLegalPlays(){
  return legalPlays;
}

int Player::getScore(){
  return score;
}

int Player::getScoreGained(){
  return scoreGained;
}

void Player::reset(){
  scoreGained = 0;
  hand.clear();
  discardPile.clear();
}

void Player::updateScore(int newScore){
  score += newScore;
}

void Player::playCard(int idx){
  currentPlay = hand[idx];
  notifyObservers();
  hand.erase(hand.begin() + idx);
}

void Player::discardCard(int idx){
  scoreGained+=hand[idx]->getRank();
  discardPile.push_back(move(hand[idx]));
  hand.erase(hand.begin() + idx);
}

int Player::findCard(shared_ptr<Card> card, vector<shared_ptr<Card>> cards){
  auto found = find_if(cards.begin(), cards.end(), [&](shared_ptr<Card>& p){
    return (p->getRank() == card->getRank() && p->getSuit() == card->getSuit());
  });
  if(found == cards.end()) { return -1; }
  int idx = distance(cards.begin(), found);
  return idx;
}

void Player::calculateLegalPlays(Table table){
  legalPlays.clear();
  for(int i = 0 ; i < hand.size(); i++){
    Rank rank = hand[i]->getRank();
    Suit suit = hand[i]->getSuit();
    if (rank == SEVEN) {
      legalPlays.push_back(hand[i]);
    }else if (table.getTable()[suit][0]->getRank() != 0 ) {
      int c = table.getTable()[suit].size();
      if (*(hand[i].get()) < *(table.getTable()[suit][0].get()) || *(hand[i].get()) > *(table.getTable()[suit][c-1].get())){
        legalPlays.push_back(hand[i]);
      }
    }
  }
}

void Player::cardsToString(vector<shared_ptr<Card>> cards){
  for (int i = 0 ; i < cards.size(); i++){
    cout << " " << cards[i]->toString();
  }
  cout << endl;
}

Info Player::getInfo() const {
  Info i = {};
  i.card = move(currentPlay);
  return i;
}
