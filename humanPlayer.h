#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <vector>
#include <string>
#include "player.h"

class HumanPlayer : public Player {
public:
  HumanPlayer();
  virtual PLAYER_TYPE playerType() const override;

  void play(std::string input);
  void discard(std::string input);
};

#endif
