#ifndef CURRENTGAME_H
#define CURRENTGAME_H

#include <chrono>
#include <filesystem>  // Include the C++ filesystem library.
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "HuntPvP.h"
#include "MasterPvP.h"
#include "NewGame.h"
#include "Player.h"
#include "PvP.h"
#include "RandomPoke.h"
#include "pokemonList.h"  // Include header files for necessary classes and libraries.
using namespace std;
namespace fs = filesystem;  // Create an alias for the filesystem namespace.

class CurrentGame : public Menu {
  string filePath;  // A private member variable to store the file path.
  string folderPath =
      "save";  // A private member variable to specify a folder path.

 public:
  CurrentGame();  // Constructor for the CurrentGame class.
  bool isFolderEmpty(
      string folderPath);  // Function to check if a folder is empty.
  void set_filePath(string _filePath);  // Function to set the file path.
  string get_filePath();                // Function to get the file path.
  string AccessFilePath();              // Function to access the file path.
  void displayMenu()
      override;  // Override the displayMenu function from the base class.
  void PokemonBehavior(
      Player& player);  // Function to handle Pokemon-related behavior.
};

#endif
