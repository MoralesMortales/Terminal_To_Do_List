#include <iostream>
#include "menu.h"

void AskAnswer();

int exit(){
  return 0;
}

void AskMenu(bool state) {
  std::cout << "What do you want to do?: \n";
  std::cout << "1. See my To-do List\n";
  std::cout << "2. Add a new To-do\n";
  std::cout << "3. Delete a To-do\n--> ";

  exist_file();

  if (state){
  AskAnswer();
  }
 }

void AskAnswer(){
  char option;
  std::cin >> option;

  while (option != '1' && option != '2' && option != '3') {
    std::cout << "Option Not valid, please choose again\n\n";
    AskMenu(false);
    std::cin >> option;
  }
}

void AskAnswerNewFile(){
  char option;
  std::cin >> option;

  while (option != '1' && option != '2') {
    std::cout << "Option Not valid, please choose again\n\n";
    FirstTimeQuestion(false);
    std::cin >> option;
  }

  if (option == '1') {
    createFile();
  }

  else {
    std::cout << "\nThanks for using our software!";
    exit();
  }

}

void FirstTimeQuestion(bool state){
std::cout << "\nLooks Like there's not any file on To-do List. Would you like to make one?\n";
std::cout << "1. Create a To-do File\n";
std::cout << "2. Cancel\n";

  if (state){
    AskAnswerNewFile();
  }
}


