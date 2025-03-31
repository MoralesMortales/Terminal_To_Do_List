#include <fstream>
#include <iostream>
#include <string>

#include "fileConfig.h"

void createFile() {
  std::ofstream newFile("ToDo.txt");

  if (newFile.is_open()) {
    newFile << "File Created successfully.\n";
    newFile.close();
  }
}

bool file_exists(std::string &fileToAnalize) {
  std::ifstream file(fileToAnalize);
  return file.good();
}

void exist_file() {
  std::string todoList = "ToDo.txt";
  if (file_exists(todoList)) {
  }

  else {
    if (!FirstTimeQuestion(true)) {
    } else {
      try {
        createFile();
      } catch (const std::system_error &e) {
        std::cerr << "System error: " << e.what() << "\n";
        std::cerr << "Error code: " << e.code() << "\n";
      } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
      } catch (...) {
        std::cerr << "Unknown error occurred while creating file.\n";
      }
      std::cout << "File Created Successfully!\n\n";
    }
  }
}
