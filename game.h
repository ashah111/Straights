#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "card.h"
#include "table.h"
#include "deck.h"
#include "player.h"
#include "computerPlayer.h"
#include "humanPlayer.h"

class Game {
  std::vector<std::shared_ptr<Player>> players;
  Deck deck;
  Table table;
  int firstPlayer;
  int currentPlayer;

  static const int PLAYER_COUNT = 4;
  static const int SCORE_TO_END = 80;

  static bool scoreSort(std::shared_ptr<Player>, std::shared_ptr<Player>);
public:
  Game(unsigned seed);
  ~Game();

  Deck getDeck();
  Table getTable();
  void getNextPlayer();

  void start();
  void beginRound();
  void takeTurn();
  void printTurn();

  void rageQuit(std::shared_ptr<Player> player);
  void addPlayer();
  bool roundOver();
  bool gameOver();

  void currentStats();
  void printWinners();

};

#endif
