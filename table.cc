#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "card.h"
#include "table.h"
#include "player.h"

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
  int suit = card->getSuit();
  int rank = card->getRank();

  if (table[suit][0]->getRank() == 0){
    table[suit].clear();
    table[suit].push_back(move(card));
  }else{
    int l = table[suit].size();
    if (rank < table[suit][0]->getRank()) {
      table[suit].insert(table[suit].begin(),move(card));
    }
    else if (rank > table[suit][l-1]->getRank()){
      table[suit].push_back(move(card));
    }
  }

}

void Table::clearTable(){
  for (int i = 0 ; i < table.size() ; i++){
    table[i].clear();
  }
  table.clear();

  for (int i = 0; i < 4 ; i++){
    vector<shared_ptr<Card>> k;
    k.emplace_back(make_shared<Card>(0,i));
    table.emplace_back(k);
  }

}

void Table::notify(Subject & whoNotified){
  Info i = whoNotified.getInfo();
  addCard(i.card);

}
