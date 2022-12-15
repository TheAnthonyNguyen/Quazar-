#include "PlayerInfo.h"

#ifndef MEDIUMSTAKES_H
#define MEDIUMSTAKES_H

class MediumStakes : public playerInfo {
 public:
  void GamePlay();
  void buy_in_med();
  void get_payout();
  void spinner1_8();
  void spinner4_7();
  int number = 0;

 private:
  int buyIn = 100;
};
#endif
