#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "deck.h"
#include "card.h"

using namespace std;

#define CARD_COUNT 52

Deck::Deck(unsigned seed): seed{seed} {
  for (int suit = 0; suit < 4; suit++){
    for (int rank = 1; rank < 14; rank++){
      cards.emplace_back(make_shared<Card>(rank,suit));
    }
  }
}

void Deck::shuffle(){
  std::default_random_engine rng{seed};
  std::shuffle( cards.begin(), cards.end(), rng );
}

vector<shared_ptr<Card>> Deck::getHand(int start, int end){
  vector<shared_ptr<Card>> hand;
  copy(cards.begin()+start,cards.begin()+end, back_inserter(hand));
  return hand;
}

void Deck::printDeck(){
  for (int i = 0 ; i < 52; i++){
    if ( i % 13 == 0 && i != 0 ) cout << endl;
    cout << cards[i]->toString() << " ";
  }
  cout << endl;
}
