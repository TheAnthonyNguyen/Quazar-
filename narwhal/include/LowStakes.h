#ifndef LOWSTAKES_H
#define LOWSTAKES_H
#include "PlayerInfo.h"

class LowStakes : public playerInfo {
 public:
  void GamePlay();
  void buy_in_low();
  void get_payout();
  void spinner1_8();
  void spinner4_7();
  int number = 0;
  int spin = 0;

 private:
  int buyIn = 20;
};

#endif
