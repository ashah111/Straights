#include <iostream>
#include <vector>
#include <string>
#include "card.h"

using namespace std;

Card::Card (int r, int s) : rank {Rank(r)}, suit {Suit(s)} {}

Suit Card::getSuit() const{
  return suit;
}

Rank Card::getRank() const{
  return rank;
}

void Card::setRank(Rank r){
  rank = r;
}

string Card::toString() const{
  return rankToString() + suitToString();
}

string Card::rankToString() const{
  switch(rank){
    case 1: return "A";
    case 2: return "2";
    case 3: return "3";
    case 4: return "4";
    case 5: return "5";
    case 6: return "6";
    case 7: return "7";
    case 8: return "8";
    case 9: return "9";
    case 10: return "10";
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    default : return "";
  }
}

string Card::suitToString() const{
  switch(suit){
    case SPADES: return "S";
    case HEARTS: return "H";
    case CLUBS: return "C";
    case DIAMONDS: return "D";
    default : return "";
  }
}

bool operator==(const Card &a, const Card &b){
  if (a.getSuit() == b.getSuit() && a.getRank() == b.getRank()) return true;
  return false;
}

bool operator<(const Card &a, const Card &b){
  if (a.getSuit() == b.getSuit() && a.getRank() + 1 == b.getRank()) return true;
  return false;
}

bool operator>(const Card &a, const Card &b){
  if (a.getSuit() == b.getSuit() && a.getRank() == b.getRank() + 1) return true;
  return false;
}
