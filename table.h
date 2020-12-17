#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "subject.h"
#include "observer.h"

class Table : public Observer{
  static const int NUM_RANK = 13;
  static const int NUM_SUIT = 4;
  std::vector<std::vector<std::shared_ptr<Card>>> table;
public:
  Table();
  ~Table();

  std::vector<std::vector<std::shared_ptr<Card>>> getTable();
  void printTable();
  void addCard(std::shared_ptr<Card> card);
  void clearTable();
  void notify( Subject & whoNotified ) override;
};

#endif
