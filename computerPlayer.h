#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>
#include "player.h"

class ComputerPlayer : public Player {
public:
  ComputerPlayer();
  ComputerPlayer( Player& humanPlayer );

  std::string playerType();
  void play();
};

#endif
