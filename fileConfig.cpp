#include <iostream>
#include <fstream> 
#include <string>

#include "fileConfig.h"

void createFile(){
    std::ofstream newFile("ToDo.txt");

        if (newFile.is_open()) {
            newFile << "File Created successfully.\n";
            newFile.close();
            std::cout << "File Created successfully.\n";
        }
}

bool file_exists(std::string& fileToAnalize){
std::ifstream file(fileToAnalize);
return file.good();
}

void exist_file(){
  std::string todoList = "ToDo.txt";
  if (file_exists(todoList)){
    std::cout << "Already a file created";
  }

  else {
    FirstTimeQuestion(true);
  }
}
