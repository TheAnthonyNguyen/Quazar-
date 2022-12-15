#ifndef PLAYERINFO_H
#define PLAYERINFO_H

class playerInfo {
 public:
  int credits = 100;
  int playerWins = 0;
  int getCredits() {
    return credits;
  }
  int getplayerWins() {
    return playerWins;
  }
  void setCredits(int i) {
    credits = i;
  }
};
#endif

