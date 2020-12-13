#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "card.h"
#include "table.h"

using namespace std;

Table::Table(){
  for (int i = 0; i < 4 ; i++){
    vector<shared_ptr<Card>> k;
    k.emplace_back(make_shared<Card>(0,i));
    table.emplace_back(k);
  }
}

Table::~Table(){}

vector<vector<shared_ptr<Card>>> Table::getTable(){
  return table;
}

void Table::printTable(){
  cout << "Cards on the table:" << endl;
  for (int i = 0; i < 4 ; i++){
    switch (i){
      case 0: cout << "Clubs: "; break;
      case 1: cout << "Diamonds: "; break;
      case 2: cout << "Hearts: "; break;
      case 3: cout << "Spades: "; break;
      default: break;
    }
    for (int j = 0; j < table[i].size() ; j++){
      cout << table[i][j]->rankToString() << " ";
    }
    cout << endl;
  }
}

void Table::addCard(shared_ptr<Card> card){
  //maybe this should observe all the players to see if they play a cards
  int suit = card->getSuit();
  int rank = card->getRank();

  if (table[suit][0]->getRank() == 0){ //Add a new 7, there's no error checking here, that must be done where called
    table[suit][0]->setRank(SEVEN);
  }else{
    int l = table[suit].size();
    if (rank < table[suit][0]->getRank()) {
      table[suit].insert(table[suit].begin(),card);
    }
    else if (rank > table[suit][l-1]->getRank()){
      table[suit].push_back(card);
    }
  }

}

void Table::clearTable(){
  for (int i = 0 ; i < table.size() ; i++){
    table[i].clear();
  }
  table.clear();
}
