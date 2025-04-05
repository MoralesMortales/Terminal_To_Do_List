#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <ostream>
#include <string>
#include <vector>

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
  int counter = 0;

  while (std::getline(inputFile, line)) {
    size_t start = line.find("--%\"");
    size_t end = line.find("\"%");

    if (start != std::string::npos && end != std::string::npos) {
      std::string content = line.substr(start + 4, end - (start + 4));
      std::cout << "\033[31m(" << counter + 1 << ") \033[0m";
      std::cout << content << std::endl;
      counter++;
      hasTasks = true;
    }
  }
  inputFile.close();

  if (!hasTasks) {
    std::cout << "\033[31m";
    std::cout << "No hay tareas en la lista.\n";
    std::cout << "\033[0m";
  }

  std::cout << "\nPress Enter to continue...\n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();

  AskMenu(true);
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

void deleteToDo() {
  std::ifstream inFile("ToDo.txt");
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(inFile, line)) {
    if (!line.empty()) {
      lines.push_back(line);
    }
  }

  inFile.close();
  int counter = lines.size();

  if (counter == 0) {
    std::cout << "\nYou don't have ToDo's created! \n\n";
  } else {

    int lineToDelete;

    do {
      std::cout << "Which line would you like to delete (1-" << counter
                << ")?: ";
      std::cin >> lineToDelete;
    } while (lineToDelete < 1 || lineToDelete > counter);

    int currentLine = 1;
    std::ofstream outFile("ToDo.txt");

    for (const std::string &l : lines) {
      if (currentLine == lineToDelete) {
        std::cout << "Deleting " << l << std::endl;
      } else {
        outFile << l << "\n";
      }
      currentLine++;
    }
    outFile.close();

    std::cout << "\nSuccessfully Erased\n\n";
  }
  AskMenu(true);
}

void editToDo() {
  std::ifstream inFile("ToDo.txt");
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(inFile, line)) {
    if (!line.empty()) {
      lines.push_back(line);
    }
  }

  inFile.close();
  int counter = lines.size();

  if (counter == 0) {
    std::cout << "\nYou don't have ToDo's created! \n\n";
  } else {

    int lineToDelete;

    do {
      std::cout << "Which To-Do would you like to edit (1-" << counter << ")?: ";
      std::cin >> lineToDelete;
    } while (lineToDelete < 1 || lineToDelete > counter);

    int currentLine = 1;
    std::ofstream outFile("ToDo.txt");

    std::string input;

    for (std::string &l : lines) {
      if (currentLine == lineToDelete) {

        std::string dummy;
        std::getline(std::cin, dummy);

        size_t start = l.find("--%\"");
        size_t end = l.find("\"%");
        std::string content = l.substr(start + 4, end - (start + 4));

        std::cout << "Editing: "<< content << std::endl << "---> "; 
        std::getline(std::cin, input);



        outFile << "--%\"" << input  << "\"%\n";

      } else {
        outFile << l << "\n";
      }
      currentLine++;
    }
    outFile.close();

    std::cout << "\nSuccessfully Erased\n\n";
  }
  AskMenu(true);
}
