#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "card.h"
#include "table.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

enum PLAYER_TYPE {HUMAN = 1, COMPUTER = 2, NONE = 3};

class Player : public Subject{
  std::vector<std::shared_ptr<Card>> hand;
  std::vector<std::shared_ptr<Card>> discardPile;
  std::vector<std::shared_ptr<Card>> legalPlays;
  int score;
  int scoreGained;
  std::shared_ptr<Card> currentPlay;
public:
  Player();

  int setHand(std::vector<std::shared_ptr<Card>> hand);
  void setDiscardPile(std::vector<std::shared_ptr<Card>> discardPile);
  void setScore(int);
  void setScoreGained(int);
  void updateScore(int newScore);

  std::vector<std::shared_ptr<Card>> getHand();
  std::vector<std::shared_ptr<Card>> getDiscardPile();
  std::vector<std::shared_ptr<Card>> getLegalPlays();
  int getScore();
  int getScoreGained();

  virtual PLAYER_TYPE playerType() const = 0;
  void reset();
  void calculateLegalPlays(Table table);
  void cardsToString(std::vector<std::shared_ptr<Card>>);

  int findCard(std::shared_ptr<Card> card,std::vector<std::shared_ptr<Card>> cards);
  void discardCard(int idx);
  void playCard(int idx);

  virtual Info getInfo() const override;


};

class InvalidValueException {};

#endif
