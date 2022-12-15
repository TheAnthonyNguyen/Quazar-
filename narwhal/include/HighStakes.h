
#include "PlayerInfo.h"
#ifndef HIGHSTAKES_H
#define HIGHSTAKES_H

class HighStakes : public playerInfo {
 public:
  void GamePlay();
  void buy_in_high();
  void get_payout();
  void spinner1_8();
  void spinner4_7();
  int spin = 0;
  int number = 0;

 private:
  int buyIn = 200;
};


#endif //HIGHSTAKES_H

