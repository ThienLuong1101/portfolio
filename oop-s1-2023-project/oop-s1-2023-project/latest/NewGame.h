#ifndef NEWGAME_H
#define NEWGAME_H

#include <chrono>      // Include the chrono library
#include <filesystem>  // Include the filesystem library
#include <fstream>     // Include the file stream library
#include <iostream>    // Include the input/output stream library
#include <string>      // Include the string library
#include <thread>      // Include the thread library

#include "Menu.h"        // Include the Menu header file
#include "Player.h"      // Include the Player header file
#include "RandomPoke.h"  // Include the RandomPoke header file
using namespace std;

namespace fs = filesystem;

// Define a class named NewGame that inherits from the Menu class
class NewGame : public Menu {
 protected:
  string Trainer_name;         // A string to store the trainer's name
  string folderPath = "save";  // A string representing the default folder path
  string filePath;             // A string to store the file path

 public:
  // Setter method to set the trainer's name
  void setTrainerName(string name);
  // Getter method to get the trainer's name
  string getTrainerName();
  // Setter method to set the folder path
  void setFolderPath(string path);
  // Getter method to get the folder path
  string getFolderPath();
  // Setter method to set the file path
  void setFilePath(string path);
  // Getter method to get the file path
  string getFilePath();
  // Method to create a folder
  void CreateFolder();

  // Override the displayMenu method from the Menu class
  void displayMenu() override;
};

#endif  // End of NEWGAME_H header guard
