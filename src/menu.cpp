#include "menu.h"
#include <cstdlib>
#include <iostream>

#include "toDoAction.h"
#include "menu.h"

void AskAnswer();

int exit() {
  std::cout << "Cerrando";
  return 0;
}

void AskMenu(bool state) {
  if (exist_file()) {

    std::cout << "\033[33m";
    std::cout << "What do you want to do?\n";
    std::cout << "\033[0m";

    std::cout << "\033[31m1.\033[0m See my To-do List\n";
    std::cout << "\033[31m2.\033[0m Add a new To-do\n";
    std::cout << "\033[31m3.\033[0m Delete a To-do\n";
    std::cout << "\033[31m4.\033[0m Edit a To-do\n";
    std::cout << "\033[31m5.\033[0m Exit\n";

    if (state) {
      AskAnswer();
    }
  };
}

void AskAnswer() {
  char option;
  std::cout << "--> ";
  std::cin >> option;

  while (option != '1' && option != '2' && option != '3' && option != '4' &&
         option != '5') {
    std::cout << "Option Not valid, please choose again\n\n";
    AskMenu(false);
    std::cout << "--> ";
    std::cin >> option;
  }

  switch (option) {
  case '1':
    readToDoList();
    break;
  case '2':
    newToDoTask();
    break;
  case '3':
    deleteToDo();
    break;
  case '4':
      editToDo();
    break;
  case '5':
    break;
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
