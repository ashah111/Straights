#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "card.h"
#include "table.h"

class Player {
  std::vector<std::shared_ptr<Card>> hand;
  std::vector<std::shared_ptr<Card>> discardPile;
  int score;
  int scoreGained;
public:
  Player();

  int setHand(std::vector<std::shared_ptr<Card>> hand);
  void setDiscardPile(std::vector<std::shared_ptr<Card>> discardPile);
  void setScore(int);
  void updateScore(int newScore);

  std::vector<std::shared_ptr<Card>> getHand();
  std::vector<std::shared_ptr<Card>> getDiscardPile();
  int getScore();
  int getScoreGained();

  std::string playerType();
  void reset();
  std::vector<std::shared_ptr<Card>> legalPlays(Table table);
  void cardsToString(std::vector<std::shared_ptr<Card>>);

  int findCard(std::string rank, std::string suit, std::vector<std::shared_ptr<Card>> cards);
  int findCard(Card* card, std::vector<std::shared_ptr<Card>> cards);
  void discardCard(std::string card);
  Card* playCard(std::string, std::vector<std::shared_ptr<Card>>);

};

class InvalidValueException {};

#endif
