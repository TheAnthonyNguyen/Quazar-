#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "HighStakes.h"
#include "PlayerInfo.h"

void HighStakes::GamePlay() {
  number = 0;
  char chooseSpinner;
  std::cout << "Which spinner would you like: " << std::endl;
  std::cout << "1) Spinner 1-8 " << std::endl << "2) Spinner 4-7 " << std::endl;
  std::cin >> chooseSpinner;
  if (chooseSpinner == '1') {
    spinner1_8();
  } else if (chooseSpinner == '2') {
    spinner4_7();
  } else {
    GamePlay();
  }
}
void HighStakes::buy_in_high() {
  credits = credits - buyIn;
  std::cout << "You currently have: " << credits << " credits" << std::endl;
}
void HighStakes::spinner1_8() {
  unsigned int seed = time(NULL);
  char chooseSpinner;
  int random = 1 + (rand_r(&seed) % 8);
  int random2 = 0 + (rand_r(&seed) % 4);
  spin = random2 + random;
  if (spin > 8) {
    spin = 8;
    number = spin + number;
  } else {
    number = spin + number;
  }

  std::cout << std::endl;
  std::cout << "You spun a " << spin << std::endl;
  std::cout << "Your total is " << number << std::endl;
  std::cout << std::endl;
  std::cout << "Which spinner would you like: " << std::endl;
  std::cout << "1) Spinner 1-8 " << std::endl << "2) Spinner 4-7 " << std::endl
      << "3) Stand" << std::endl;
  std::cin >> chooseSpinner;

  if (chooseSpinner == '1' && number < 20) {
    spinner1_8();
  } else if (chooseSpinner == '2' && number < 20) {
    spinner4_7();
  } else if (chooseSpinner == '3' || number > 20) {
    get_payout();
  } else {
    std::cout << "Wrong input please start again " << std::endl;
    GamePlay();
  }
}
void HighStakes::spinner4_7() {
  unsigned int seed = time(NULL);
  char chooseSpinner;
  int random = 4 + (rand_r(&seed) % 7);
  int random2 = 0 + (rand_r(&seed) % 4);
  spin = random2 + random;
  if (spin > 7) {
    spin = 7;
    number = spin + number;
  } else {
    number = spin + number;
  }

  std::cout << std::endl;
  std::cout << "You spun a " << spin << std::endl;
  std::cout << "Your total is " << number << std::endl;
  std::cout << std::endl;
  std::cout << "Which spinner would you like: " << std::endl;
  std::cout << "1) Spinner 1-8 " << std::endl << "2) Spinner 4-7 " << std::endl
      << "3) Stand" << std::endl;
  std::cin >> chooseSpinner;

  if (chooseSpinner == '1' && number < 20) {
    spinner1_8();
  } else if (chooseSpinner == '2' && number < 20) {
    spinner4_7();
  } else if (chooseSpinner == '3' || number > 20) {
    get_payout();

  } else {
    std::cout << "Wrong input please start again " << std::endl;
    GamePlay();
  }
}
void HighStakes::get_payout() {
  credits = getCredits();
  if (number == 15) {
    credits = credits + buyIn + (buyIn * 0.25);
    playerWins++;
  } else if (number == 16) {
    credits = credits + buyIn + (buyIn * 0.50);
    playerWins++;
  } else if (number == 17) {
    credits = credits + buyIn + (buyIn * 1);
  } else if (number == 18) {
    credits = credits + buyIn + (buyIn * 1.25);
    playerWins++;
  } else if (number == 19) {
    credits = credits + buyIn + (buyIn * 1.50);
    playerWins++;
  } else if (number == 20) {
    credits = credits + buyIn + (buyIn * 2);
    playerWins++;
  }

  std::cout << "Your total credits are " << getCredits() << std::endl;
}
