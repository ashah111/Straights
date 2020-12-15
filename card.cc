#include <iostream>
#include <vector>
#include <string>
#include "card.h"

using namespace std;

Card::Card (int r, int s) : rank {Rank(r)}, suit {Suit(s)} {}

Card::Card () {}

Card::Card (string r, string s) : rank {stringToRank(r)}, suit {stringToSuit(s)} {}

Suit Card::getSuit() const{
  return suit;
}

Rank Card::getRank() const{
  return rank;
}

void Card::setRank(Rank r){
  rank = r;
  cout  << " here2 /n" << endl;
}

void Card::setSuit(int s){
  suit = Suit(s);
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
    case 10: return "T";
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

Rank Card::stringToRank(string input) const{
  if (input == "A") return ACE;
  else if (input == "2") return TWO;
  else if (input == "3") return THREE;
  else if (input == "4") return FOUR;
  else if (input == "5") return FIVE;
  else if (input == "6") return SIX;
  else if (input == "7") return SEVEN;
  else if (input == "8") return EIGHT;
  else if (input == "9") return NINE;
  else if (input == "T") return TEN;
  else if (input == "J") return JACK;
  else if (input == "Q") return QUEEN;
  else if (input == "K") return KING;
  else return X;
}

Suit Card::stringToSuit(string input) const{
  if (input == "S") return SPADES;
  else if (input == "D") return DIAMONDS;
  else if (input == "C") return CLUBS;
  else if (input == "H") return HEARTS;
  else return SPADES;
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
