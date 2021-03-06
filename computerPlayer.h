#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <vector>
#include <string>
#include "player.h"

class ComputerPlayer : public Player {
public:
  ComputerPlayer();
  ComputerPlayer( std::shared_ptr<Player> humanPlayer );
  virtual PLAYER_TYPE playerType() const override;
  void play();
};

#endif
