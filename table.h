#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include "card.h"

class Table {
  std::vector<std::vector<std::shared_ptr<Card>>> table;
public:
  Table();
  ~Table();

  std::vector<std::vector<std::shared_ptr<Card>>> getTable();
  void printTable();
  void addCard(std::shared_ptr<Card> card);
  void clearTable();
};

#endif
