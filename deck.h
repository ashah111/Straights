#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include "card.h"

class Deck {
  std::vector<std::shared_ptr<Card>> cards;
  unsigned seed;
public:
  Deck();
  Deck(unsigned seed);

  void shuffle();
  std::vector<std::shared_ptr<Card>> getHand(int start, int finish);
  void printDeck();
};

#endif
