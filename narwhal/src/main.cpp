#include "PlayerInfo.h"
#include "LowStakes.h"
#include "MediumStakes.h"
#include "HighStakes.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

int main() {
  srand((unsigned) time(NULL));
  playerInfo info;
  LowStakes low;
  MediumStakes medium;
  HighStakes high;
  int totalcredits = 100;

  char chooseStake;

  std::cout << "=====QUAZAR====" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Your starting/current credits is: " << info.getCredits()
      << std::endl;
  do {
    if (totalcredits < 20) {
      std::cout << "You do not have enough credits to play. Closing game."
          << std::endl;
      exit(0);
    } else {
      std::cout << "Which betting level would you like to choose?: "
          << std::endl;
      std::cout << "1) 20 credits" << std::endl << "2) 100 credits"
          << std::endl << "3) 200 credits" << std::endl << "4) Leave Game"
          << std::endl;

      std::cin >> chooseStake;

      if (chooseStake == '1') {
        if (totalcredits < 20) {
          std::cout << "You do not have enough credits to play." << std::endl;
        } else {
          low.setCredits(totalcredits);
          low.buy_in_low();
          low.GamePlay();
          totalcredits = low.getCredits();
        }
      }

      if (chooseStake == '2') {
        if (totalcredits < 100) {
          std::cout << "You do not have enough credits to play." << std::endl;
        } else {
          medium.setCredits(totalcredits);
          medium.buy_in_med();
          medium.GamePlay();
          totalcredits = medium.getCredits();
        }
      }

      if (chooseStake == '3') {
        if (totalcredits < 200 || high.getplayerWins() > 2) {
          std::cout << "You do not have sufficient credits and player wins"
              << std::endl;
        } else {
          std::cout << totalcredits << std::endl;
          high.setCredits(totalcredits);
          high.buy_in_high();
          high.GamePlay();
          totalcredits = high.getCredits();
        }
      }

      if (chooseStake == '4' || totalcredits < 20) {
        std::cout << "You have left the game." << std::endl;
        std::cout << "Your credits is: " << totalcredits << std::endl;
        exit(0);
      }

      if (!isdigit(chooseStake)) {
        std::cout << "Your input is incorrect" << std::endl;
      }
    }
  } while (totalcredits >= 20 || chooseStake == '4');
  return 0;
}


