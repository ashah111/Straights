#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <vector>
#include <string>
#include "player.h"

class HumanPlayer : public Player {
public:
  HumanPlayer();
  std::string playerType();
};

#endif
