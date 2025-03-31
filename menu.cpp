#include "menu.h"
#include <cstdlib>
#include <iostream>

void AskAnswer();

int exit() {
  std::cout << "Cerrando";
  return 0;
}

void AskMenu(bool state) {
  exist_file();

  std::cout << "What do you want to do?\n";
  std::cout << "1. See my To-do List\n";
  std::cout << "2. Add a new To-do\n";
  std::cout << "3. Delete a To-do\n";

  if (state) {
    AskAnswer();
  }
}

void AskAnswer() {
  char option;
  std::cin >> option;

  while (option != '1' && option != '2' && option != '3') {
    std::cout << "Option Not valid, please choose again\n\n";
    AskMenu(false);
    std::cin >> option;
  }
  std::cout << "\n";
}

bool AskAnswerNewFile() {
  char option;
  std::cout << "--> ";
  std::cin >> option;

  while (option != '1' && option != '2') {
    std::cout << "Option Not valid, please choose again\n";
    if (FirstTimeQuestion(false)) {
  std::cout << "--> ";
      std::cin >> option;
    } else {
      break;
    }
  }
      std::cout << "\n";

  if (option == '1') {
    return true;
  }

  else {
    return false;
  }
}

bool FirstTimeQuestion(bool state) {
  std::cout << "Looks Like there's not any file on To-do List. Would you "
               "like to make one?\n";
  std::cout << "1. Create a To-do File\n";
  std::cout << "2. Cancel\n";

  if (state) {
    if (AskAnswerNewFile()) {
      return true;
    } else {
      return false;
    }
  }
  return true;
}
