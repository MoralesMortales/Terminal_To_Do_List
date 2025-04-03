#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include "menu.h"
#include "toDoActions.h"

void readToDoList() {
  std::ifstream inputFile("ToDo.txt");
  std::cout << std::endl;
  if (!inputFile.is_open()) {
    std::cerr << "Error: The file didnt open." << std::endl;
    return;
  }

  std::string line;
  bool hasTasks = false;

  while (std::getline(inputFile, line)) {
    size_t start = line.find("--%\"");
    size_t end = line.find("\"%");

    if (start != std::string::npos && end != std::string::npos) {
      std::string content = line.substr(start + 4, end - (start + 4));
      std::cout << "Tarea: " << content << std::endl;
    }
  }
  inputFile.close();
}

void newToDoTask() {
  std::string dummy;
  std::getline(std::cin, dummy);

  std::string task;
  std::cout << "Add a new Task!: ";
  std::getline(std::cin, task);
  std::cout << "\nDone!\n\n";

  std::ofstream outputFile("ToDo.txt", std::ios::app);
  if (!outputFile) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  outputFile << "--%\"" << task << "\"%\n";
  outputFile.close();

  AskMenu(true);
}
