#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>

enum Suit {OTHER = 0, SPADES = 3, HEARTS = 2, DIAMONDS = 1, CLUBS = 0 };
enum Rank { X = 0, ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
  Rank rank;
  Suit suit;
public:
  Card (int rank, int suit);
  Card ();
  Card (std::string rank, std::string suit);
  void setRank(Rank rank);
  void setSuit(int suit);
  Suit getSuit() const;
  Rank getRank() const;
  std::string toString() const;

  std::string rankToString() const;
  std::string suitToString() const;
  Rank stringToRank(std::string input) const;
  Suit stringToSuit(std::string input) const;
};

bool operator==(const Card &, const Card &);
bool operator<(const Card &, const Card &);
bool operator>(const Card &, const Card &);

#endif
