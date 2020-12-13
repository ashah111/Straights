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
  score = 0;
}

vector<shared_ptr<Card>> Player::getHand(){
  return hand;
}

vector<shared_ptr<Card>> Player::getDiscardPile(){
  return discardPile;
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

Card* Player::playCard(string card, vector<shared_ptr<Card>> legalPlays){
  int idx;
  string rank,suit;
  if (card.length() > 0){
    if (card.length() != 2) throw InvalidValueException(); // return error
    rank = card.substr(0,1);
    suit = card.substr(1,1);

    idx = findCard(rank,suit,legalPlays);
    if (idx == -1) throw InvalidValueException();
  }else {

  }
    idx = findCard(rank,suit,hand);


  Card * ret = hand[idx].get();
  hand.erase(hand.begin() + idx);
  return ret;
}

void Player::discardCard(string card){
  if (card.length() != 2) return; // return error
  string rank = card.substr(0,1);
  string suit = card.substr(1,1);

  int idx = findCard(rank,suit,hand);
  if (idx == -1) return; //ERROR
  scoreGained+=hand[idx]->getRank();
  discardPile.push_back(move(hand[idx]));
  hand.erase(hand.begin() + idx);
}

int Player::findCard(string rank, string suit, vector<shared_ptr<Card>> cards){
  auto found = find_if(cards.begin(), cards.end(), [&](shared_ptr<Card>& p){
    return (p->rankToString() == rank && p->suitToString() == suit);
  });
  if(found == cards.end()) { return -1; }
  int idx = distance(hand.begin(), found);
  return idx;
}

int Player::findCard(Card *card, vector<shared_ptr<Card>> cards){
  auto found = find_if(cards.begin(), cards.end(), [&](shared_ptr<Card>& p){
    return (p.get() == card);
  });
  if(found == cards.end()) { return -1; }
  int idx = distance(hand.begin(), found);
  return idx;
}

vector<shared_ptr<Card>> Player::legalPlays(Table table){
  vector<shared_ptr<Card>> legalPlays;
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

  return legalPlays;
}

void Player::cardsToString(vector<shared_ptr<Card>> cards){
  for (int i = 0 ; i < cards.size(); i++){
    //cout << " " << cards[i]->toString();
    cout << i << endl;
  }
  cout << endl;
}

string Player::playerType(){return "";}










//asdsa
